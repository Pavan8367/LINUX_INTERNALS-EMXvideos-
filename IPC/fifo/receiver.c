#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

//receiver process
int main()
{

	//open the FIFO file in particular mode
	int fd = open("/tmp/my_fifo",O_RDONLY);

	//Receiving the data from FIFO
	char buf[100];
	if(read(fd,buf,20) < 0)
	{
		perror("read");
		return -1;
	}

	printf("Receiving data = %s\n",buf);
	return 0;
}
