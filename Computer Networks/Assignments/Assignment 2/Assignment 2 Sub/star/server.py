import socket

#WRITE CODE HERE:
#1. Create a KEY-VALUE pairs (Create a dictionary OR Maintain a text file for KEY-VALUES).

# Data is stored in data_server.txt file
# This data is read and stored in a dictionary
file_name = './data_server.txt'
with open(file_name, 'r') as f:
  data = f.readlines()
  data = [x.strip().split(":") for x in data]
  data_dictionary = dict(data)

# Code to write the data dictionary to data_server.txt file
def write_to_file(data_dictionary, file_name):
  with open(file_name, 'w') as f:
    for key, value in data_dictionary.items():
      f.write("%s:%s\n" % (key, value))

# Code for GET request
def get_request(key, data_dictionary):
  if key in data_dictionary:
    return "HTTP/1.1 " + "200 OK\n\n " + key + ":" + data_dictionary[key]
  else:
    return "HTTP/1.1 " + "404 NOT FOUND\n\n " + key

# Code for PUT request
def put_request(key, value, data_dictionary, file_name):
  if key in data_dictionary:
    data_dictionary[key] = value
    write_to_file(data_dictionary, file_name)
    return "HTTP/1.1 " + "200 OK\n\n " + key + ":" + value
  
  else:
    data_dictionary[key] = value
    write_to_file(data_dictionary, file_name)
    return "HTTP/1.1 " + "201 OK\n\n " + key + ":" + value

# server_ip = str(input("Enter Server IP: "))
server_ip = "10.0.1.3"
print("\nUsing Server IP: " + server_ip)
dport = 12346

s = socket.socket()
print ("\nSocket successfully created")

s.bind((server_ip, dport))
print ("Socket binded to %s" %(dport))

s.listen(5)
print ("Socket is listening\n")

while True:
  c, addr = s.accept()
  print ('Got connection from', addr)
  recvmsg = c.recv(1024).decode()
  
  print("\nServer received this message from cache: " + recvmsg)

  # Parse the received HTTP request
  request_type = recvmsg.split(" ")[0]
  
  # If request is GET type
  if request_type == "GET":
    key = recvmsg.split(" ")[1].split("=")[-1]
    send_message = get_request(key, data_dictionary)
  
  # If request is PUT type
  elif request_type == "PUT":
    key = recvmsg.split(" ")[1].split("=")[1].split("&")[0]
    value = recvmsg.split(" ")[1].split("=")[-1]
    send_message = put_request(key, value, data_dictionary, file_name)

  # If request is neither GET or PUT type
  else:
    send_message = "HTTP/1.1 400 BAD REQUEST\n\n"
  
  # Send response
  c.send(send_message.encode())
  print("\nServer sent: " + send_message + "\n")
  
  c.close()