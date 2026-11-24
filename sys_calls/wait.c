#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t ret_pid = fork();

	if(ret_pid > 0)   //parent
	{
		printf("This is parent with pid -> %d, parent PID -> %d\n",getpid(),getppid());
		int status;
		pid_t res = wait(&status);
		printf("Child %d terminated with exit status %d\n",res,status);
		printf("Parent terminating\n");
	}

	else if(ret_pid == 0) //child
	{
		
		printf("This is child with PID -> %d, parent PID -> %d\n",getpid(),getppid());
		sleep(15);
		
		printf("Child terminating\n");
		
	}

	else
	{
		perror("fork");
		return -1;
	}
	return 0;
}
