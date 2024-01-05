Steps for Executing Basic topology:
1. Follow the steps as given in the assignment, open up the nodes for each host (h1 and h2) and run the bash scripts for each host (eg., bash h1-arp.sh). 
2. Run the server side python script (on h2) first, and then the client sides (on h1).
3. The client will prompt the user to enter the type of request (GET, PUT or DELETE),and corresponding key and/or value as required.
4. Every time a request response is received, the existing socket connection is closed. A new one is immediately opened. This will keep happening until 'EXIT' is entered (To exit the program)

Steps for Executing the Star topology:
1. Follow the steps as given in the assignment, open up the nodes for each host (h1, h2 and h3) and run the bash scripts for each host (eg., bash h1-arp.sh).
2. Run the python scripts in this order - server(h3), cache(h2) and client(h1).
3. The client will prompt the user to enter the type of request (GET or PUT),and corresponding key and/or value as required.
4. Every time a request response is received, the existing socket connection between client and server is closed. A new one is immediately opened. This will keep happening until 'EXIT' is entered (To exit the program)


Overview of basic topology's client.py and server.py scripts:
- dst ip is 10.0.1.2, which is h2's IP address. 
- At client side, the user is prompted to specify what request they would like to send. The message is encoded and sent to the socket. 
- The type can be 'GET', 'PUT', 'DELETE' or 'EXIT'.
- The server receives this message and creates a connection.
- The message (recvmsg) is the decoded message, which is then parsed. The corresponding reply is decided by the server and written to send_message.
- send_message is sent through the socket, and the connection is closed by the server.
- The client then receives this and prints the value it received (if a GET request sent) or an acknowledgement (if PUT or DELETE).The socket connnection is immediately closed and a new one is opened (until 'EXIT' type request entered)
- if 'EXIT' requested, socket connection closed (new one not opened).

Overview of star topology's client.py, cache.py and server.py scripts:
- the dst_ip in this case is the IP address of the cache (10.0.1.2)
- Now on the client side, only a 'GET' request can be sent to the cache ('PUT' requests are also available but it is not part of the original question whereas it was specified in FAQs section). 'EXIT' is also permitted, but that is for a different purpose.
- The script for client.py is exactly the same with the exception of ability to send a 'DELETE' request.
- On the cache side, the cache is meant to act as a server to the client, and as a client to the server. Server IP is '10.0.1.3'.
First, a socket connection is made with the client and it listens for messages from the client (h1). The message is received and parsed (recvmsg).
- Parsing the client's request: From the received GET request, we check if the requested key is present in the cache's database. If it is present, the response 'send_message' is formed and sent. If the key is not present however, cache requests the key value from the server via the 'fetch_from_server' function. This function creates a new socket connection with the server and sends over a GET request. The received response is read by the cache - if the response data is valid, it is written to the cache database. The response from the server is also forwarded to the client.


Points to Note:
- The database is stored in the server side (and cache) in a textfile. In the server side implementation (and cache as well), the database is copied to a python dictionary.
- As an when we modify this dictionary, we write it to the corresponding textfile.
- For easier testing, the dstIP, serverIP, etc were hardcoded in the scripts, instead of making them user inputs.
- HTTP response codes we used:
	1. 200 - succesful GET response or succesful PUT updating of an existing key.
	2. 201 - succesful adding of a key value pair (if it had been deleted and added again, generally)
	3. 400 - request sent is invalid / cannot be understood by the machine
	4. 404 - requested key does not exist/ not found
- PCAP file will not be present for h3 for when the requested key value pair is present in the cache. This is because involvement of server is not there => no activity.
