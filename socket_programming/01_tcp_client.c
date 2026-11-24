/*
Author : Pavan
Title : IPC Mechanism - Usage of TCP socket - client
Description : Socket offer interface with TCp/IP stack inside linux 
kernel, using which remote connection can be established 
over a network. this program is demonstrate various steps 
to established successful three-way handshake as a client
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

#define SERVER_IP_ADDRESS	"127.0.0.1"
#define SERVER_PORT		5002
#define CLIENT_BUFF_SIZE	20

int main()
{
	int sock_fd,c_size;
	struct sockaddr_in serv_addr;
	char client_buffer[CLIENT_BUFF_SIZE];

	/*Create a client socket*/
	sock_fd = socket(AF_INET,SOCK_STREAM,0);

	/*Bind with client socket is optional here*/

	/*populate it with server's address details*/
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(SERVER_PORT);
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRESS);

	/*Get the msg from the client*/
	char buf[100];
	printf("Enter the message you want to send to server:\n");
	scanf("%[^\n]",buf);

	/*connect request to server appication*/
	if(connect(sock_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr)) != 0)
	{
		perror("connect");
		close(sock_fd);
		exit(1);
	}

	else
	{
		printf("Connection Successful\n");
	}

	/*send the message to server*/
	c_size = send(sock_fd, buf, strlen(buf) + 1, 0);

	if(c_size > 0)
		printf("message sent to server successfully please check\n");
	else
		perror("send");

	/*Receive the data from the server*/
	recv(sock_fd,buf,40,0);
	printf("data from the server is --> %s\n",buf);

	close(sock_fd);

}
