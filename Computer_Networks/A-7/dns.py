'''

Write a program for DNS lookup.
Given IP address input, it should return URL andvice-versa
'''
import socket
choose=True
while choose:
	print("\nMenu\n(1)Get Host by Name \n(2)Get Host by Address\n(3)Quit")
	choose=raw_input("Enter the choice ")
	if choose=="1":
		addr1 = socket.gethostbyname('google.com')
		print(addr1)
		
	elif choose=="2":
		addr3=socket.gethostbyaddr("216.58.199.142")
		print(addr3)
        elif choose=="3":
		exit()	
        else:
        	print("Invalid choice, please choose again")
        	print("\n")
        	
'''
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL $ python dns.py

Menu
(1)Get Host by Name 
(2)Get Host by Address
(3)Quit
Enter the choice 1
216.58.197.78

Menu
(1)Get Host by Name 
(2)Get Host by Address
(3)Quit
Enter the choice 2
('bom07s01-in-f14.1e100.net', [], ['216.58.199.142'])

Menu
(1)Get Host by Name 
(2)Get Host by Address
(3)Quit
Enter the choice 3
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL $ 
''' 
