/*
Author : Pavan
Title : IPC Mechanism - Usage of TCP socket - server
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
	int sock_fd,data_sock_fd,buffer_len;
	struct sockaddr_in serv_addr,client_info;
	char serv_buffer[SERVER_BUFF];

	printf("Server is waiting....\n");

	/*Create a TCP socket*/
	sock_fd = socket(AF_INET,SOCK_STREAM,0);

	/*Bind it into particular IP address & port*/
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
	serv_addr.sin_port = htons(SERVER_PORT);

	if(bind(sock_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr) ) == -1)
	{
		perror("bind");
		return -1;
	}
	/*listen for the incomming connection*/
	listen(sock_fd,SERVER_LEN);

	int len = sizeof(client_info);

	/*if there are any, accept and create a new data socket*/
	data_sock_fd = accept(sock_fd,(struct sockaddr*)&client_info,&len);

	memset(serv_buffer,0,sizeof(serv_buffer));

	/*try to get some actual data from the client*/
	recv(data_sock_fd,(void*)serv_buffer,SERVER_BUFF,0);

	/*print the data received from the client*/
	printf("Client Ip -> %s\nClient port -> %d\n",inet_ntoa(client_info.sin_addr),ntohs(client_info.sin_port));
	printf("Client data -> %s\n",serv_buffer);

	/*Sending the data to client*/
	char buf[] = "Pavan sending to client from the server";
	send(data_sock_fd,buf,strlen(buf) + 1,0);

	/*closing */
	close(data_sock_fd);
	close(sock_fd);

}
