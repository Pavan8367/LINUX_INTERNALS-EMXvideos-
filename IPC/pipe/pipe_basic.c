#include<stdio.h>
#include<unistd.h>

int main()
{
	//create pipe

	int pipefd[2];
	if(pipe(pipefd) == -1)
	{
		perror("pipe");
		return -1;
	}

	printf("pipefd[0] -> %d\n",pipefd[0]);
	printf("pipefd[1] -> %d\n",pipefd[1]);

	return 0;
}
