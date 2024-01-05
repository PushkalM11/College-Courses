import socket

# Data is stored in data_cache.txt file
# This data is read and stored in a dictionary
file_name = './data_cache.txt'
with open(file_name, 'r') as f:
  data = f.readlines()
  data = [x.strip().split(":") for x in data]
  data_dictionary = dict(data)

# Code to write the data dictionary to data.txt file
def write_to_file(data_dictionary, file_name):
  with open(file_name, 'w') as f:
    for key, value in data_dictionary.items():
      f.write("%s:%s\n" % (key, value))

# Code to fetch data from server
def fetch_from_server(key, server_ip, server_port):
  s_to_server = socket.socket()
  s_to_server.connect((server_ip, server_port))

  send_message = "GET /assignment2?request=" + key + " HTTP/1.1\n\n"
  s_to_server.send(send_message.encode())
  received_message = s_to_server.recv(1024).decode()

  s_to_server.close()

  return received_message

# Cache acts as a server to the client and as a client to the server
# cache_ip = str(input("Enter Cache IP: "))
# server_ip = str(input("Enter Server IP: "))

cache_ip, server_ip = "10.0.1.2", "10.0.1.3"
print("\nUsing Cache IP: " + cache_ip)
print("Using Server IP: " + server_ip)
print("Connecting to server: " + server_ip)

client_port = 12345
server_port = 12346

s_to_client = socket.socket()
print("\nSocket successfully created")

s_to_client.bind((cache_ip, client_port))
print("Socket binded to %s" %(client_port))

s_to_client.listen(5)
print("Socket is listening")

while True:
    c, addr = s_to_client.accept()
    print('\nGot connection from'+ str(addr))
    
    recvmsg = c.recv(1024).decode()
    print("\nCache received: "+ recvmsg)
    # Parse the received HTTP request
    request_type = recvmsg.split(" ")[0]
    
    # If request is GET type
    if request_type == "GET":
        key = recvmsg.split(" ")[1].split("=")[-1]
        if key in data_dictionary:
            send_message = "HTTP/1.1 " + "200 OK\n\n " + key + ":" + data_dictionary[key]
        else:
            print("\nFetching requested data from server...")
            server_received_message = fetch_from_server(key, server_ip, server_port)
            
            print("\nCache received this message from server: " + server_received_message)
            error = server_received_message.split(" ")[1]

            if error != "404":
                value = server_received_message.split(" ")[-1].split(":")[-1]
                data_dictionary[key] = value
                
                write_to_file(data_dictionary, file_name)
                
                print("\n" + key + " added to cache with value " + value)
            
            send_message = server_received_message
    
    # If request is PUT type
    elif request_type == "PUT":
        
        # Relaying message to server
        s_to_server = socket.socket()
        s_to_server.connect((server_ip, server_port))

        server_send_message = recvmsg
        s_to_server.send(server_send_message.encode())
        server_received_message = s_to_server.recv(1024).decode()
        s_to_server.close()

        send_message = server_received_message

    # If request is neither GET or PUT type
    else:
        send_message = "HTTP/1.1 400 BAD REQUEST\n\n"

    # Send response
    c.send(send_message.encode())
    print("\nCache sent: " + send_message + "\n")

    c.close()
