# chat_client.py

import sys, socket, select

def chat_client():
    if(len(sys.argv) < 3):
    					#'''check whether sufficient arguments are provided'''
	print 'Usage : python chat_client.py hostname port'
        sys.exit()

    host = sys.argv[1]
    port = int(sys.argv[2])

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#"""The first argument AF_INET is the address domain of the
#socket. This is used when we have an Internet Domain with
#any two hosts The second argument is the type of socket.
#SOCK_STREAM means that data or characters are read in
#a continuous flow."""
    s.settimeout(2)

    # connect to remote host
    try :
        s.connect((host, port))
    except :
        print 'Unable to connect'
        sys.exit()

    print 'Connected to remote host. You can start sending messages'
    #sys.stdout.write('[Me] '); sys.stdout.flush()

    while 1:
        socket_list = [sys.stdin, s]

        # Get the list sockets which are readable
        read_sockets, write_sockets, error_sockets = select.select(socket_list , [], [])
         #  """ There are two possible input situations. Either the
    #user wants to give  manual input to send to other people,
    #or the server is sending a message  to be printed on the
    #screen. Select returns from sockets_list, the stream that
    #is reader for input. So for example, if the server wants
    #to send a message, then the if condition will hold true
    #below.If the user wants to send a message, the else
    #condition will evaluate as true"""
        for sock in read_sockets:
            if sock == s:
                # incoming message from remote server, s
                data = sock.recv(4096)
                if not data :
                    print '\nDisconnected from chat server'
                    sys.exit()
                else :
                    #print data
                    print "\n"+data
                    #sys.stdout.write(data)
                    #sys.stdout.write('[Me] '); sys.stdout.flush()

            else :
                # user entered a message
                msg = raw_input()
                s.send(msg)
                #sys.stdout.write('[Me] '); sys.stdout.flush()

if __name__ == "__main__":

    sys.exit(chat_client())
