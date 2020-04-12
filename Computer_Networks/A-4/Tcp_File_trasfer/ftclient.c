/*
Write a program using TCP socket for wierd network for following:
File transfer-(client side)*/

#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>   //Internet protocol lib main socket header
#include<sys/types.h>	//Used for Datatypes
#include<netinet/in.h>	//Internet Address Family contains sin family
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>  //Internet operations like htons ntohl
#include<error.h>

#define ERROR -1
#define BUFFER 102400

int main(int argc, char **argv)
{
	int sock; 				// client socket descriptor

	struct sockaddr_in remote_server;

	char send_data[BUFFER]= "hi From lalit"; // send buffer: hold information to send to server
	char recv_data[BUFFER];	// receive buffer: hold information to received from server

	int sockaddr_len = sizeof(struct sockaddr_in); // socket address length
	int data_len; // store data length of send_data or recv_data length

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket error. ");
		exit(-1);
	}

	remote_server.sin_family = AF_INET; //IPv4
	remote_server.sin_port = htons(atoi(argv[2])); //htons: host to network short byte order, atoi: convert a string to an integer
	remote_server.sin_addr.s_addr = inet_addr(argv[1]); //inet_addr: function converts the Internet host address cp IPv4 numbers-and-dots notation into binary 									data in network byte order.
	bzero(&remote_server.sin_zero , 8);// function sets the first 8 bytes of the area starting at &remote_server.sin_zero to zero

	if((connect(sock, (struct sockaddr*)&remote_server, sockaddr_len)) == -1)
	{
		perror("connect error");
		exit(-1);
	}


	FILE *f;
	char name[30];
	printf("\nEnter file name to Transfer \n");
	scanf("%s",name);
	f=fopen(name,"r");
	fgets(send_data,BUFFER,f);
	fclose(f);
	//fscanf(f,"%50s",buffer);
	write(sock,send_data,strlen(send_data));




	printf("\nthe file was sent successfully. \n");

	close(sock);
	return 0;
}


/*
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/File_trasfer pending$ ./a.out 127.0.0.1 8090
*/
