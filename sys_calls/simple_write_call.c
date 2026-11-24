#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd;

	char msg[] = "Hello pavan ! How much the life geting hard you can overcome that..:)";

	fd = open("pavan.txt",O_WRONLY | O_CREAT| O_TRUNC | 0644);

	if(fd == -1)
	{
		perror("open");
		return -1;
	}
	if(write(fd,msg,sizeof(msg)-1) == -1)
	{
		perror("write");
		return -1;
	}
	close(fd);
	return 0;
}
