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
		read(sock,buffer,sizeof(buffer));
		printf("\nCLIENT : %s",buffer);
		if(strncmp("exit",buffer,4) == 0)
		{
			printf("CLIENT EXITED ");
			break;
		}
		bzero(buffer,MAX);
		printf("YOU : ");
		scanf("%s",buffer);
		write(sock,buffer,sizeof(buffer));
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
	server.sin_addr.s_addr = INADDR_ANY;
	
	if((bind(sock,(struct sockaddr *)&server,sockaddr_len)) == -1)
	{
		perror("BIND ERROR");
		exit(-1);
	}
	
	if((listen(sock,10)) == -1)
	{
		perror("LISTENING ERROR");
		exit(-1);
	}
	
	if((cli = accept(sock,(struct sockaddr *)&client,&sockaddr_len)) == -1)
	{
		perror("ACCEPT ERROR");
		exit(-1);
	}
	funct(cli);
	close(sock);
	return(0);
}
		
