
import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 



sock.connect(('127.0.0.1',23000)) #addind host ip and port number

sock.send("hi from client")

while True:
	
	data = sock.recv(16) #receive the data from the server
	if "stop" in data:
		break
	else:			
		print "server: " + data

	data = raw_input("you: ")
	sock.send(data)
	if "stop" in data:
		break
sock.close()




