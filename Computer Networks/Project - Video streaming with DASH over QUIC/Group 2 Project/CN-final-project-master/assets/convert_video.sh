ffmpeg -i test3.mp4 -c:v libx264 -b:v 100k -c:a aac -b:a 128k -movflags +faststart ./Videos/test3_100kbps.mp4
ffmpeg -i test3.mp4 -c:v libx264 -b:v 200k -c:a aac -b:a 128k -movflags +faststart ./Videos/test3_200kbps.mp4
ffmpeg -i test3.mp4 -c:v libx264 -b:v 400k -c:a aac -b:a 128k -movflags +faststart ./Videos/test3_400kbps.mp4
ffmpeg -i test3.mp4 -c:v libx264 -b:v 800k -c:a aac -b:a 128k -movflags +faststart ./Videos/test3_800kbps.mp4