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
		pid_t res = waitpid(ret_pid,&status,0);
		if(WIFEXITED(status))
		{
			printf("Child %d terminated normally with exit code %d\n",res,WIFEXITED(status));
		}
		else
		{
			printf("Child %d terminated abnormally with the exit code %d\n",res,status);
		}
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
