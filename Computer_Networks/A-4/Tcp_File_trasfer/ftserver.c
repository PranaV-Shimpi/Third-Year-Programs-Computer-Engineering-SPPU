/*
Write a program using TCP socket for wierd network for following:
File transfer-(server side)*/

#include<stdio.h>
#include<stdlib.h>

#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<error.h>

#define ERROR -1
#define BUFFER 102400
#define MAX_CLIENTS 2

int main(int argc, char **argv)
{
	int sock, cli; // sock: server socket descriptor, cli: client socket descriptor
	struct sockaddr_in server, client;

	char send_data[BUFFER]= "Hello from Lalit"; // send buffer: hold information to send to client
	char recv_data[BUFFER]; // receive buffer: hold information to received from client

	int sockaddr_len = sizeof(struct sockaddr_in); // socket address length
	int data_len; // store data length of send_data or recv_data length

	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket error. ");
		exit(-1);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1]));
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero , 8);

	if((bind(sock, (struct sockaddr *)&server, sockaddr_len)) == -1)
	{
		perror("bind error");
		exit(-1);
	}

	if((listen(sock,10)) == -1)
	{
		perror("listen error");
		exit(-1);
	}

	while(1)
	{
		if((cli = accept(sock, (struct sockaddr*)&client, &sockaddr_len )) == -1)
		{
			perror("accept error");
			exit(-1);
		}
		printf("New client connected to port: %d and IP %s \n", ntohs(client.sin_port), inet_ntoa(client.sin_addr));



		FILE *fp;
		read(cli,recv_data,100);

		fp=fopen("add1.txt","w");
		fprintf(fp,"%s",recv_data);
		fclose(fp);




		printf("\nthe file was received successfully\n");
		printf("\nthe new file created is add1.txt\n\n");



		printf("client disconnected \n");
		close(cli);
	}
	return 0;
}


/*


res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/File_trasfer pending$ gcc ftserver.c
res@res-HP-280-G2-MT-Legacy:~/Desktop/FINAL /assignment 7/File_trasfer pending$ ./a.out 8090
New client connected to port: 47294 and IP 127.0.0.1

the file was received successfully

the new file created is add1.txt

client disconnected

*/
