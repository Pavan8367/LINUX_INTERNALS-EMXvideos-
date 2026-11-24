/*Number Sender with Pause/Resume
Problem:
A child process generates numbers using a thread.
Numbers are sent to parent using a pipe.
Parent prints the numbers.
Signal Use:
SIGUSR1 → Pause sending
SIGUSR2 → Resume sending*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<pthread.h>
#include<signal.h>

int pipe_fd[2];
volatile sig_atomic_t paused = 0;

void handler_paused(int sig)
{
	paused = 1;
}
void handler_resume(int sig)
{
	paused = 0;
}
//producer thread
void* producer(void *arg)
{
	int num = 1;
	while(1)
	{
		if(!paused)
		{
			sleep(1);
			write(pipe_fd[1],&num,sizeof(num));
			num++;
		}	
	}
	return NULL;
}
int main()
{
	pipe(pipe_fd);

	pid_t pid = fork();


	if(pid < 0)
	{
		perror("fork");
		exit(1);
	}

	if(pid == 0)
	{	printf("child PID = %d\n",getpid());
		close(pipe_fd[0]);

		signal(SIGUSR1,handler_paused);
		signal(SIGUSR2,handler_resume);

		pthread_t t;
		pthread_create(&t,NULL,producer,NULL);
		pthread_join(t,NULL);
	}

	if(pid > 0)
	{
		close(pipe_fd[1]);
		int num;

		while(1)
		{
			int bytes = read(pipe_fd[0],&num,sizeof(num));
			if(bytes > 0)
				printf("Received --> %d\n",num);
		}
	}
	return 0;
}
