#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	size_t ret1,ret2;
	char buf[100];

	//open the file in read mode
	int fd1 = open("f1.txt",O_RDONLY);

	if(fd1 == -1)
	{
		perror("open");
		return -1;
	}

	//open the file in write mode
	int fd2 = open("f2.txt",O_WRONLY);

	if(fd2 == -1)
	{
		perror("open");
		return -1;
	}

	do
	{
		ret1 = read(fd1,buf,20);
		printf("reading ret number of bytes : %lu\n",ret1);
		ret2 = write(fd2,buf,ret1);
		printf("writing ret number of bytes : %lu\n",ret2);
	}
	while(ret1 == 20);
	close(fd1);
	close(fd2);
	return 0;
}
