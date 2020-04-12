
import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # create socket object

sock.bind(('localhost',23000)) #bind to the port

sock.listen(1) # server is in the listening mode        listen(backlog)  backlog = queue of connection

clisock, (ip,port) = sock.accept() # establishing connecton with client

while True:    	
	data = clisock.recv(16)

	if "stop." in data:
		break
	else:			
		print "client: " + data
	
	data = raw_input("you: ")
	clisock.send(data)
	if "stop." in data:
		break
sock.close()
            
