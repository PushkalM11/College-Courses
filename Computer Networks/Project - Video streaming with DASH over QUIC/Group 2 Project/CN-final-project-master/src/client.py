import asyncio
import configparser
import logging
import random
import signal
import ssl
from string import ascii_letters, digits
import sys
from pathlib import Path
from typing import cast, Optional
import numpy as np
import cv2
import struct
import os
from convert import fisheyeImgConv

from aioquic.asyncio import connect, QuicConnectionProtocol
from aioquic.quic import events
from aioquic.quic.configuration import QuicConfiguration

sys.path.insert(1, os.path.abspath("src/client_files/"))

from videoplayer import select_video

try:
    import uvloop
except ImportError:
    uvloop = None

config = configparser.ConfigParser()
config.read("config.ini")

ENCODING: str = config["DEFAULT"]["Encoding"]
FILE_WAIT_TIME: float = float(config["CLIENT"]["FileWaitTime"])
FILE_MAX_WAIT_TIME: float = float(config["CLIENT"]["FileMaxWaitTime"])
DEFAULT_LOG_PATH: str = str(config["CLIENT"]["LogPath"])
MAX_DATAGRAM_SIZE = int(config["DEFAULT"]["MaxDatagramSize"])


class DashPlayback:
    """
    Audio[bandwidth] : {duration, url_list}
    Video[bandwidth] : {duration, url_list}
    """
    def __init__(self):

        self.min_buffer_time = None
        self.playback_duration = None
        self.audio = dict()
        self.video = dict()

def id_generator(id_size=6):
    """ Module to create a random string with uppercase 
        and digits.
    """
    return 'TEMP_' + ''.join(random.choice(ascii_letters+digits) for _ in range(id_size))

def get_vlc_path_for_current_platform(platform: str = sys.platform) -> Path:
    if platform == "linux" or platform == "linux2":
        return Path("/usr/bin/vlc")
    elif platform == "darwin":
        return Path("/Applications/VLC.app/Contents/MacOS/VLC")
    elif platform == "win32":
        return Path("%PROGRAMFILES%\\VideoLAN\\VLC\\vlc.exe")

def convert_image(frame, params):
    mapper = fisheyeImgConv()
    FOV, Theta, Phi, output_shape = params
    Hd, Wd = output_shape
    return mapper.eqruirect2persp(frame, FOV, Theta, Phi, Hd, Wd)

mpd_stram_ids = []
cmpd = os.path.abspath("src/client_data/client.mpd")
with open(cmpd, 'wb'):
    pass  

def reorder_in_axis(array, axis, order):
    l = np.array(array).shape[axis]
    out_array = np.zeros_like(array)
    for i in range(l):
        out_array[:, :, i] = array[:, :, order[i]]
    return out_array

class VideoStreamClientProtocol(QuicConnectionProtocol):    
    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self._ack_waiter: Optional[asyncio.Future[None]] = None
        self.vlc_process = None
        self.buffer = b""
        self.payload_size = struct.calcsize("L")
        self.buffer = bytearray()
        self.Theta = 0
        self.FOV = 80
        self.alpha = 0
        self.out_shape = [300, 533]
        self.Phi = 0
        self.last_received_size = 0
        self.last_received_timestamp = 0
        self.total_received_size = 0
        self.bitrate = 800
        self.frame_change = 3
        self.diff_theta = 5
        self.diff_phi = 5
        self.cyclic_flag = 2
        self.k0 = 0
        self.k1 = 0
        self.k2 = 0

    async def send_mpd_req(self)->None:
        stream_id = self._quic.get_next_available_stream_id()
        mpd_stram_ids.append(stream_id)
        self._quic.send_stream_data(
            stream_id, f"GET mpd".encode(ENCODING), end_stream=False
        )
        waiter = self._loop.create_future()
        self._ack_waiter = waiter
        self.transmit()
        return await asyncio.shield(waiter)
    
    async def fetch_video(self):
        current_bitrate = self.bitrate
        file = "test3"
        await self.send_request_for_video(file, current_bitrate, 0)
        seg_total = 299
        for i in range(1, seg_total):
            current_bitrate = self.bitrate
            self.frame_change += 1
            if self.cyclic_flag % 3 == 0:
                self.k0 += 1
                self.k1 += 1
                self.k2 += 1
            self.cyclic_flag += 1

            if current_bitrate > 40000:
                await self.send_request_for_video(file, 800, i)
            elif current_bitrate > 20000:
                await self.send_request_for_video(file, 400, i)
            else:
                await self.send_request_for_video(file, 200, i)
        return
    
    def send_params(self):
        self.stream_id4 = self._quic.get_next_available_stream_id()
        params = f"POST {self.FOV} {self.Theta} {self.alpha} {self.Phi} {self.out_shape}"
        self._quic.send_stream_data(
            self.stream_id4, params.encode(ENCODING), end_stream=True
            )
        

    async def send_request_for_video(self, filename: str, bitrate, seg_num) -> None:
        stream_id1 = self._quic.get_next_available_stream_id()
        self._quic.send_stream_data(
            stream_id1, f"GET segment {filename} {bitrate} {seg_num} {self.FOV} {self.Theta} {self.alpha} {self.Phi}".encode(ENCODING), end_stream=False
        )

        waiter = self._loop.create_future()
        self._ack_waiter = waiter
        self.transmit()
        return await asyncio.shield(waiter)
    
    def quic_event_received(self, event: events.QuicEvent) -> None:
        if self._ack_waiter is not None:
            if isinstance(event, events.StreamDataReceived): 
                data_size = len(event.data)

                # Update the total received size
                self.total_received_size += data_size

                # Calculate the bitrate every second
                current_time = asyncio.get_event_loop().time()
                elapsed_time = current_time - self.last_received_timestamp

                if elapsed_time >= 1:
                    # Calculate the bitrate
                    self.bitrate = (self.total_received_size / elapsed_time) / 1000
                    self.last_received_size = 0
                    self.last_received_timestamp = current_time
                    
                self.buffer.extend(event.data)
                if not hasattr(self, 'frame_size'):
                    self.frame_size = int.from_bytes(self.buffer, 'big')
                    self.buffer = bytearray()
                else:
                    while len(self.buffer) >= self.frame_size:
                        # Extract frame data from the buffer
                        frame_data = self.buffer[:self.frame_size]
                        self.buffer = self.buffer[self.frame_size:]

                        # Decode the frame
                        decoded_frame = np.frombuffer(frame_data, dtype = np.uint8)
                        decoded_frame = decoded_frame.reshape(300, 533, 3)
                        
                        if self.frame_change % 3 == 0:
                            new_image = np.roll(decoded_frame, shift = -1 * (self.frame_change + self.k0), axis = 1)

                        elif self.frame_change % 3 == 1:
                            new_image = np.roll(decoded_frame, shift = -1, axis = 2)
                            new_image = np.roll(new_image, shift = -1 * (self.frame_change + self.k1), axis = 1)

                        elif self.frame_change % 3 == 2:
                            new_image = np.roll(decoded_frame, shift = -2, axis = 2)
                            new_image = np.roll(new_image, shift = -1 * (self.frame_change + self.k2), axis = 1)

                        cv2.imshow('Received', new_image)
                        self.send_params()

                        key = cv2.waitKey(1) & 0xFF
                        if key == ord('q'):
                            break

                        elif key == ord('d'):  # Increase Theta
                            self.Theta += self.diff_theta
                            print("Client requested Right")

                        elif key == ord('a'):  # Decrease Theta
                            self.Theta -= self.diff_theta
                            print("Client requested Left")

                        elif key == ord('w'):  # Increase Phi
                            self.Phi += self.diff_phi
                            print("Client requested Up")

                        elif key == ord('s'):  # Decrease Phi
                            self.Phi -= self.diff_phi
                            print("Client requested Down")

                if event.end_stream:
                    waiter = self._ack_waiter
                    self._ack_waiter = None
                    waiter.set_result(None)

async def run(
    config: QuicConfiguration, host: str, port: int, requested_video: str
) -> None:
    async with connect(
        host=host,
        port=port,
        configuration=config,
        create_protocol=VideoStreamClientProtocol,
    ) as client:
        client = cast(VideoStreamClientProtocol, client)
        await client.fetch_video()

def clean_up(sig, frame):
    sys.exit(0)


if __name__ == "__main__":
    signal.signal(signal.SIGINT, clean_up)

    defaults = QuicConfiguration(
        is_client=True, max_datagram_frame_size=MAX_DATAGRAM_SIZE
    )
    # Set Up Logging
    log_path = Path(DEFAULT_LOG_PATH)
    log_path.parent.mkdir(parents=True, exist_ok=True)
    logging.basicConfig(
        filename=str(log_path),
        format="%(asctime)s.%(msecs)03d %(levelname)-8s %(message)s",
        level=logging.INFO,
        datefmt="%Y-%m-%d %H:%M:%S",
    )

    configuration = QuicConfiguration(is_client=True)
    configuration.verify_mode = ssl.CERT_NONE
    temp_host = '127.0.0.1'
    temp_port = '8000'

    if uvloop is not None:
        uvloop.install()

    loop = asyncio.get_event_loop()
    loop.run_until_complete(
        run(
            config=configuration,
            host=temp_host,
            port=int(temp_port),
            requested_video=select_video(),
        )
    )