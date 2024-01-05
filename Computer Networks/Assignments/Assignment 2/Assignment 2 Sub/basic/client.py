import socket

# dst_ip = str(input("Enter dstIP: "))
# print(dst_ip)
server_IP = "10.0.1.2"
print("\nServer IP: " + server_IP)
port = 12346

#Write your code here:
#1. Add code to send HTTP GET / PUT / DELETE request. The request should also include KEY.
#2. Add the code to parse the response you get from the server.
# s.send('Hello server'.encode())
# print ('Client received '+s.recv(1024).decode())

# Some lines to indicate usage
def print_info():
    print("\nThe request types available are: GET, PUT and DELETE")
    print("To exit the program, enter 'EXIT' as the request type")

s = socket.socket()
s.connect((server_IP, port))

print("\nConnection established!")

print_info()
request_type = str(input("Enter request type: "))

while request_type != "EXIT":
    # If request is GET type
    if request_type == "GET":
        key = input("Enter key: ")
        send_message = request_type + " /assignment2?request=" + key + " HTTP/1.1"

    # If request is PUT type
    elif request_type == "PUT":
        key = input("Enter key: ")
        value = input("Enter value: ")
        send_message = request_type + " /assignment2/" + key + "/" + value + " HTTP/1.1"

    # If request is DELETE type
    elif request_type == "DELETE":
        key = input("Enter key: ")
        send_message = request_type + " /assignment2/" + key + " HTTP/1.1"

    # If request is invalid
    else:
        print("\nInvalid request type!\n")
        print_info()
        request_type = str(input("Enter request type: "))
        continue

    print("\nClient sent: ", send_message)    
    send_message += "\n\n"
    s.send(send_message.encode())
    received_message = s.recv(1024).decode()
    print('\nClient received: ' + received_message)

    if request_type == "GET":
        error = received_message.split(" ")[1]
        if error == "404":
            print("\nNo value found for: " + key)
        else:
            print("\nThe value for " + key + " is: " + received_message.split(" ")[-1].split(":")[-1])

    if request_type == "PUT":
        error = received_message.split(" ")[1]
        if error == "200":
            print("\nValue for " + key + " updated!")
        else:
            print("\nValue for " + key + " added!")

    if request_type == "DELETE":
        error = received_message.split(" ")[1]
        if error == "404":
            print("\nNo value found for: " + key)
        else:
            print("\nValue for " + key + " deleted!")

    s.close()
    print("\nConnection closed!")

    s = socket.socket()
    s.connect((server_IP, port))

    print("\nNew connection established!")

    print_info()
    request_type = str(input("Enter request type: "))

s.close()
print("\nConnection closed!\n")