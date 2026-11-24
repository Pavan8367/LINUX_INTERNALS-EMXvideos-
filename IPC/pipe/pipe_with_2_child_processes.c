//This is how to implement the pipe between two processes

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

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
		pid_t c2 = fork();
		if(c2 > 0)//parent
		{
			close(pipefd[0]);
			close(pipefd[1]);
			//wait for the child process
			wait(NULL);
			wait(NULL);
		}
		else if(c2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0],0);
			//used to execute the cmd "wc"
			execl("/bin/wc","wc",NULL);
		}
	}

	else if(c1 == 0) //child
	{
		close(pipefd[0]);
		dup2(pipefd[1],1);
		//used to execute the cmd "ls"
		execl("/bin/ls","ls",NULL);

	}

	return 0;
}
