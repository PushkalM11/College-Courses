import asyncio
import configparser
import logging
import os
import time
from pathlib import Path
from typing import Dict, Callable, Union
import cv2
from aioquic.asyncio import QuicConnectionProtocol
from aioquic.quic import events
from aioquic.quic.connection import QuicConnection
from aioquic.quic.events import StreamDataReceived
from convert import fisheyeImgConv
import matplotlib.pyplot as plt

os.environ["IMAGEIO_FFMPEG_EXE"] = "/opt/homebrew/bin/ffmpeg"
    
config = configparser.ConfigParser()
config.read("config.ini")

CACHE_PATH: Path = Path(config["SERVER"]["CachePath"])
ENCODING = config["DEFAULT"]["Encoding"]
FPS: int = int(config["DEFAULT"]["FPS"])

FILES_PATH = "./src/server_data/Videos/"
MAX_DATAGRAM_SIZE = 65536

out_shape = [300, 533]

def convert_image(frame, params):
    mapper = fisheyeImgConv()
    FOV, Theta, Phi, output_shape = params
    Hd, Wd = output_shape
    return mapper.eqruirect2persp(frame, FOV, Theta, Phi, Hd, Wd)

class VideoStreamRequestHandler:    
    def __init__(
        self,
        protocol: QuicConnectionProtocol,
        connection: QuicConnection,
        stream_ended: bool,
        stream_id: int,
        transmit: Callable[[], None],
        file_to_serve: Path,
        cache_path: Path,
        params: list
    ):
        self.protocol = protocol
        self.connection = connection
        self.stream_id = stream_id
        self.queue: asyncio.Queue[Dict] = asyncio.Queue()
        self.transmit = transmit
        self.file_to_serve = file_to_serve
        self.cache_path = cache_path
        self.params = params
        if stream_ended:
            self.queue.put_nowait({"type": "videostream.request"})

    async def stream(self):

        await self.send_frames()
        # logging.info("Sent frames successfully")
        self.connection.send_stream_data(self.stream_id, b"", end_stream=True)

    async def send_frames(self):
        cap = cv2.VideoCapture(self.file_to_serve)
        flag = True
        while(cap.isOpened()):
            ret, frame = cap.read()
            if ret == True:
                params = self.params
                processed_frame = convert_image(frame, params).flatten()
                encoded_data = processed_frame.tobytes()
                
                if flag:
                    frame_size = len(encoded_data)
                    frame_size_bytes =  frame_size.to_bytes(4, 'big')
                    self.connection.send_stream_data(self.stream_id, frame_size_bytes)
                    flag = False
                    self.transmit()
                self.connection.send_stream_data(self.stream_id, encoded_data)
            else:
                break
            self.transmit()
        cap.release()
        cv2.destroyAllWindows()

Handler = Union[VideoStreamRequestHandler]

class VideoStreamServerProtocol(QuicConnectionProtocol):
    
    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self._handlers: Dict[int, Handler] = {}
        self.out_shape = [300, 533]
    def quic_event_received(self, event: events.QuicEvent) -> None:
        if isinstance(event, StreamDataReceived):
            data = event.data.decode(ENCODING)
            query = data.split()
            logging.info(f"Query: {query}")

            if query[0] == "POST":
                global FOV
                global theta
                global alpha
                global phi
                global out_shape
                FOV = float(query[1])
                theta = float(query[2])
                alpha = float(query[3])
                phi = float(query[4])
                logging.info(f"{query}")
                out_shape = [int(query[5][1:len(query[5])-1]), int(query[6][:len(query[6])-1])]
                return
            
            if query[0] == 'GET' and query[1] == 'mpd':
                file_to_serve = os.path.abspath("src/server_data/manifest.mpd")
                try:
                    with open(file_to_serve, 'rb') as request_file:
                        data = request_file.read()
                        self._quic.send_stream_data(
                            event.stream_id,
                            data,
                            end_stream=True,
                        )
                        now = time.time()
                        print("sent mpd")
                except FileNotFoundError:
                    print("File not found.")
                except Exception as e:
                    print(f"An error occurred: {e}")
                
                return
            
            if query[0] == 'GET' and query[1] == 'segment':
                fname = query[2]
                bitrate = int(query[3])
                segment_no = int(query[4])
                FOV = float(query[5])
                theta = float(query[6])
                alpha = float(query[7])
                phi = float(query[8])
                params = [FOV, theta, phi, self.out_shape]
                file_to_serve = os.path.abspath(f"src/server_data/Videos/{fname}_{bitrate}kbps_{segment_no}.mp4")
                logging.info(f"File to serve: {file_to_serve}")
                session_cache_path = CACHE_PATH / str(event.stream_id)
                
                handler = VideoStreamRequestHandler(
                    connection=self._quic,
                    protocol=self,
                    stream_ended=False,
                    stream_id=event.stream_id,
                    transmit=self.transmit,
                    file_to_serve=file_to_serve,
                    cache_path=session_cache_path,
                    params = params
                )
                self._handlers[event.stream_id] = handler
                asyncio.ensure_future(handler.stream())