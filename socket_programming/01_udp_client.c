/*
Author : Pavan
Title : IPC Mechanism - Usage of UDP socket - Client
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
#define CLIENT_BUFF	100

int main()
{
	int sock_fd,c_size;
	struct sockaddr_in cli_addr,client_info,serv_addr;
	char cli_buffer[CLIENT_BUFF];

	printf("Server is waiting....\n");

	/*Create a TCP socket*/
	sock_fd = socket(AF_INET,SOCK_DGRAM,0);

	/*Bind it into particular IP address & port*/
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	/*Get the message from client*/
	printf("Enter the message you want to send to server:\n");
	scanf("%[^\n]",cli_buffer);

	//send message to server
	c_size = sendto(sock_fd,cli_buffer,strlen(cli_buffer)+1,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
			if(c_size)
			printf("Message sent to server successfully, please check\n");
			else
			printf("ERROR : Message sending failed\n");

			close(sock_fd);
			}
