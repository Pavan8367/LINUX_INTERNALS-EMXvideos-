#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>

int main()
{

	//opening the f1.txt in read mode..
	int fd = open("f1.txt",O_RDONLY);

	//checking for error..
	if(fd == -1)
	{
		perror("open");
		return -1;
	}

	char buf[50];

	//reading 20 bytes from the FD..
	size_t res = read(fd,buf,20);

	//printing the return value..
	printf("res = %lu\n",ret); 

	//printing the buf
	printf("%s\n",buf);
}
