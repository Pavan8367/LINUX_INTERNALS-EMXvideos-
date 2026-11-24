/*
Author : Pavan
Title : IPC Mechanism - Usage of UDP socket - server
Description : Socket offer interface with TCp/IP stack inside linux 
kernel, using which remote connection can be established 
over a network. this program is demonstrate various steps 
to established successful three-way handshake as a server
 */

#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERVER_IP	"127.0.0.1"
#define SERVER_PORT	5002
#define SERVER_LEN	10
#define SERVER_BUFF	100

int main()
{
	int sock_fd,data_sock_fd,buffer_len,cli_len;
	struct sockaddr_in cli_addr,client_info,serv_addr;
	char serv_buffer[SERVER_BUFF];

	printf("Server is waiting....\n");

	/*Create a TCP socket*/
	sock_fd = socket(AF_INET,SOCK_DGRAM,0);

	/*Bind it into particular IP address & port*/
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	if(bind(sock_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr) ) == -1)
	{
		perror("bind");
		return -1;
	}

	/*Try to get some actual data from client*/
cli_len = sizeof(struct sockaddr_in);
recvfrom(sock_fd,(void*)serv_buffer,SERVER_BUFF,0,(struct sockaddr*)&cli_addr,&cli_len);


/*Print the data received from the client*/
printf("Here is the client data: %s\n",serv_buffer);

printf("Sender info:\n");
printf("Sender IP address: %s\n",inet_ntoa(cli_addr.sin_addr));
printf("Sender port: %d\n",ntohs(cli_addr.sin_port));

/*close the socket*/
close(sock_fd);

}
