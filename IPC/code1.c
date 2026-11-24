#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<pthread.h>

#define BUFFER_SIZE 10
volatile sig_atomic_t stop = 0;
int pipe_fd[2];

//shared buffer
int buffer[BUFFER_SIZE];
int count = 0;

//mutex + condition
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//signal handler
void handle_sigint(int sig)
{
	stop = 1;
	pthread_cond_broadcast(&cond);//wake waiting thread
}
//producer thread
void * producer(void * arg)
{
	int num = 1;

	while(!stop)
	{
		pthread_mutex_lock(&lock);

		if(count < BUFFER_SIZE)
		{
			buffer[count++] = num++;
			pthread_cond_signal(&cond);
		}
		pthread_mutex_unlock(&lock);
		usleep(200000);//slowdown
	}
	pthread_exit(NULL);
}

//sender thread
void* sender(void* arg)
{
	while(!stop || count > 0)
	{
		pthread_mutex_lock(&lock);

		while(count == 0 && !stop)
		{
			pthread_cond_wait(&cond,&lock);
		}
		if(count > 0)
		{
			int value = buffer[--count];
			write(pipe_fd[1],&value,sizeof(value));
		}

		pthread_mutex_unlock(&lock);
	}
	pthread_exit(NULL);
}
int main()
{
	pid_t pid;

	if(pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(1);
	}

	//register signal handler
	signal(SIGINT,handle_sigint);

	pid = fork();

	if(pid < 0)
	{
		perror("fork");
		exit(1);
	}

	//child process

	if(pid == 0)
	{
		close(pipe_fd[0]);//close read end

		pthread_t prod_thread,send_thread; //creating two threads producer and sender

		pthread_create(&prod_thread,NULL,producer,NULL);
		pthread_create(&send_thread,NULL,sender,NULL);

		pthread_join(prod_thread,NULL);
		pthread_join(send_thread,NULL);

		close(pipe_fd[1]);//close write end
		printf("\nchild exiting...\n");
		fflush(stdout);
	}

	if(pid > 0)
	{
		close(pipe_fd[1]);//closing pipe write end..
		int value;

		while(!stop)
		{
			int bytes = read(pipe_fd[0],&value,sizeof(value));

			if(bytes > 0)
				printf("Parent recieved : %d\n",value);
			else if(bytes == 0)
			{
				break;//pipe closed..
			}
		}

		close(pipe_fd[0]);
		wait(NULL);
		printf("\nparent exiting\n");
		fflush(stdout);
	}
	return 0;
}
