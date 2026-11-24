#include<stdio.h>
#include<fcntl.h>

int main()
{
	//open in rd mode
	int fd1 = open("f1.txt",O_RDONLY);
	int fd2 = open("f2.txt",O_RDONLY);
	if(fd1 == -1)
	{
		perror("open");
		return -1;
	}

	printf("Fd1 = %d\n",fd1);
	printf("Fd2 = %d\n",fd2);
	return 0;
}
