
import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(('', 10000))                                                 # sock.bind((UDP_IP, UDP_PORT))

msg, (ip, port) = sock.recvfrom(100)                                    # recvfrom(buffer size)
print "client connected to ip: " + ip + " and port: " + str(port)
print "received message: " + msg
sock.sendto("Hello from server", (ip,port))



while True:    	
	msg, (ip, port) = sock.recvfrom(100)
	print "client connected to ip: " + ip + " and port: " + str(port)
	if "stop." in msg:
		break
	else:			
		print "client: " + msg
	
	msg = raw_input("you: ")
	sock.sendto(msg, (ip,port))
	if "stop." in msg:
		break
sock.close()
        

