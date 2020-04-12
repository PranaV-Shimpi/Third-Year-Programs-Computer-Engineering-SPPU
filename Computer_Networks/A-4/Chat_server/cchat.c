#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<arpa/inet.h>
#include<netinet/in.h>
#include<error.h>

#define MAX 1024
#define ERROR -1

void funct(int sock)
{
	char buffer[MAX];
	char msg[50];
	bzero(buffer,MAX);
	for(;;)
	{	
		bzero(buffer,MAX);
		printf("YOU : ");
		scanf("%s",buffer);
		write(sock,buffer,sizeof(buffer));
		read(sock,buffer,sizeof(buffer));
		printf("\nSERVER : %s",buffer);
		if(strncmp("exit",buffer,4) == 0)
		{
			printf("SERVER EXITED ");
			break;
		}
		
		
	}
}

int main(int argc,char **argv)
{
	int sock,cli;
	struct sockaddr_in server,client;
	int sockaddr_len = sizeof(struct sockaddr_in);
	
	if((sock = socket(AF_INET,SOCK_STREAM,0)) == -1)
	{
		perror("SOCKET ERROR ");
		exit(-1);
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1]));
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	if((connect(sock,(struct sockaddr *)&server,sockaddr_len)) == -1)
	{
		perror("ERROR IN CONNECTION");
		exit(-1);
	}
	funct(sock);
	close(sock);
	return(0);
}
		
