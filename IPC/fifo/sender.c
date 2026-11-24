#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	//create fifo
	if(mkfifo("/tmp/my_fifo",0644) == -1)
	{
		perror("mkfifo");
		return -1;
	}


	//open the FIFO file in particular mode
	int fd = open("/tmp/my_fifo",O_WRONLY);
	char str[100];
	printf("Ente the string:");
	scanf("%[^\n]",str);
	//sending the data to FIFO

	if(write(fd,str,strlen(str)+1) == -1)
	{
		perror("write");
		return -1;
	}
	return 0;
}
