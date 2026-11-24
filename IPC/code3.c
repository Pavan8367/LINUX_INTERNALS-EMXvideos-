#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<pthread.h>
#include<signal.h>
#include<sys/stat.h>
#include<fcntl.h>

#define THREADS 3
#define CHUNK_SIZE 100

int pipe_fd[2];
volatile sig_atomic_t stop = 0;

void handler_sigint(int sig)
{
	stop = 1;
}

//reader
void *reader(void* arg)
{
	int thread_id = *(int*) arg;
	int fd = open("input.txt",O_RDONLY);

	if(fd < 0)
	{
		perror("open");
		return NULL;
	}

	char buffer[CHUNK_SIZE];
	off_t offset = thread_id * CHUNK_SIZE;

	lseek(fd,offset,SEEK_SET);

	while(!stop)
	{
		int bytes = read(fd,buffer,CHUNK_SIZE);

		if(bytes <= 0)
			break;

		write(pipe_fd[1],buffer,bytes);
		sleep(1);
	}
	close(fd);
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
	{
		close(pipe_fd[0]);

		signal(SIGINT,handler_sigint);

		pthread_t thread[THREADS];
		int ids[THREADS];

		for(int i = 0;i < THREADS;i++)
		{
			ids[i] = i;
			pthread_create(&thread[i],NULL,reader,&ids[i]);
		}
		for(int i = 0;i < THREADS;i++)
		{
			pthread_join(thread[i],NULL);
		}

		close(pipe_fd[1]);
		printf("Child exiting\n");
		exit(0);
	}

	else
	{
		close(pipe_fd[1]);

		char buffer[CHUNK_SIZE];

		while(1)
		{
			int bytes = read(pipe_fd[0],buffer,CHUNK_SIZE);

			if(bytes > 0)
			{
				write(STDOUT_FILENO,buffer,bytes);
			}
			else
			{
				break;
			}
		}

		close(pipe_fd[0]);
		printf("Parent is Exiting\n");
	}
	return 0;
}
