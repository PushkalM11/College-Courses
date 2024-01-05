This code contains our implementation of streaming 360 degree video using DASH over QUIC.
The source codes are in src directory. Files are as follows:
1) client.py contains the code for client
2) server.py contains the code for server

Run server:
python3 -m src.server -c ssl_cert.pem -k ssl_key.pem --host 127.0.0.1 --port 8000

Run client:
python -m src.client