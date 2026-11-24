#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	//open the f1.txt in write mode.
	int fd = open("f2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	int new_stdout = dup2(1,5);

	int new_fd = dup2(fd,1);
	printf("Print this message into FILE.....!\n");
	fflush(stdout);

	dup2(new_stdout,1);

	printf("Print This message into STDOUT\n");

	return 0;
}
