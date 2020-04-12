
import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto("Hi from client", ('', 10000))
while True:    	
	msg, (ip, port) = sock.recvfrom(100)

	if "stop." in msg:
		break
	else:			
		print "server: " + msg
	
	msg = raw_input("you: ")
	sock.sendto(msg, (ip,port))
	if "stop." in msg:
		break
sock.close()

