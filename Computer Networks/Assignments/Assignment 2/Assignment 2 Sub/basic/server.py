import socket

#WRITE CODE HERE:
#1. Create a KEY-VALUE pairs (Create a dictionary OR Maintain a text file for KEY-VALUES).

# Data is stored in data.txt file
# This data is read and stored in a dictionary
file_name = './data.txt'
with open(file_name, 'r') as f:
  data = f.readlines()
  data = [x.strip().split(":") for x in data]
  data_dictionary = dict(data)
  
# Code to write the data dictionary to data.txt file
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

# Code for DELETE request
def delete_request(key, data_dictionary, file_name):
  if key in data_dictionary:
    del data_dictionary[key]
    write_to_file(data_dictionary, file_name)
    return "HTTP/1.1 " + "200 OK\n\n " + key
  else:
    return "HTTP/1.1 " + "404 NOT FOUND\n\n " + key

# dst_ip = str(input("Enter Server IP: "))
server_IP = "10.0.1.2"
print("\nUsing Server IP: " + server_IP)
dport = 12346

s = socket.socket()
print ("\nSocket successfully created")

s.bind((server_IP, dport))
print ("Socket binded to %s" %(dport))

s.listen(5)
print ("Socket is listening\n")

while True:
  c, addr = s.accept()
  print ('Got connection from', addr)
  recvmsg = c.recv(1024).decode()
  print('\nServer received: '+recvmsg)
  # c.send('Hello client'.encode())
  
  #Write your code here
  #1. Uncomment c.send 
  #2. Parse the received HTTP request
  #3. Do the necessary operation depending upon whether it is GET, PUT or DELETE
  #4. Send response
  ##################

  # Parse the received HTTP request
  # First we detect the type of request
  request_type = recvmsg.split(" ")[0]
  
  # If request is GET type
  if request_type == "GET":
    key = recvmsg.split(" ")[1].split("=")[-1]
    send_message = get_request(key, data_dictionary)
  
  # If request is PUT type
  elif request_type == "PUT":
    key, value = recvmsg.split(" ")[1].split("/")[-2 : ]
    send_message = put_request(key, value, data_dictionary, file_name)
  
  # If request is DELETE type
  elif request_type == "DELETE":
    key = recvmsg.split(" ")[1].split("/")[-1]
    send_message = delete_request(key, data_dictionary, file_name)
  
  # If request is not GET, PUT or DELETE type
  else:
    send_message = "HTTP/1.1 400 BAD REQUEST\n\n"
  
  # Send response
  c.send(send_message.encode())
  print("\nServer sent: " + send_message + "\n")
  
  c.close()