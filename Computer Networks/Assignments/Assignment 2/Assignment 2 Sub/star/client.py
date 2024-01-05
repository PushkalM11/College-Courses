import socket

# cache_ip = str(input("Enter dstIP: "))
# print(cache_ip)
cache_ip = "10.0.1.2"
print("\nUsing Cache IP: " + cache_ip)
port = 12345

#Write your code here:
#1. Add code to send HTTP GET / PUT / DELETE request. The request should also include KEY.
#2. Add the code to parse the response you get from the server.
# s.send('Hello server'.encode())
# print ('Client received '+s.recv(1024).decode())

# Some lines to indicate usage
def print_info():
    print("\nThe request types available are: GET and PUT")
    print("To exit the program, enter 'EXIT' as the request type")

s = socket.socket()
s.connect((cache_ip, port))

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
        send_message = request_type + " /assignment2?request=" + key + "&value=" + value + " HTTP/1.1"

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

    s.close()
    print("\nConnection closed!\n")
    
    s = socket.socket()
    s.connect((cache_ip, port))
    
    print("\nNew connection established!")
    
    print_info()
    request_type = str(input("Enter request type: "))

s.close()
print("\nConnection closed!\n")
