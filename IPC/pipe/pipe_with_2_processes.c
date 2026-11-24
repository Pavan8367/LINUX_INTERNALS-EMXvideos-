//This is how to implement the pipe between two processes

#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
	//create pipe

	int pipefd[2];
	if(pipe(pipefd) == -1)
	{
		perror("pipe");
		return -1;
	}

	pid_t c1 = fork();

	if(c1 > 0)  //parent
	{
		close(pipefd[0]);
		char buf[100] = "HI Pavan\n";
		write(pipefd[1],buf,strlen(buf) + 1);
	}

	else if(c1 == 0) //child
	{
		close(pipefd[1]);
		char buf[100];
		read(pipefd[0],buf,20);
		printf("Result = %s\n",buf);
	}

	return 0;
}
