
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	pid_t ret_pid = fork();

	if(ret_pid > 0)
	{
		printf("This is parent with pid -> %d, parent PID -> %d\n",getpid(),getppid());
		sleep(15);
		printf("Parent terminating\n");
	}

	else if(ret_pid == 0)
	{
		printf("This is child with PID -> %d, parent PID -> %d\n",getpid(),getppid());
		sleep(5);
		printf("Child terminating\n");
	}

	else
	{
		perror("fork");
		return -1;
	}
	return 0;
}
