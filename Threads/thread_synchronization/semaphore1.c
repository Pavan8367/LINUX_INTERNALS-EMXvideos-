#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define NO_OF_THREADS  10

//create the object variable for the semaphore
sem_t my_count;

int no;
void *thread(void *arg)
{
	//check the resources count if availabke it allow else don't
	sem_wait(&my_count);
	int n = ++no;
	for(int i = 0;i < 5;sleep(1),i++)
	{
		printf("Threads %d running %d times\n",n,i+1);
	}
	//increase the resource count if the thread execution is completed
	sem_post(&my_count); 
}
int main()
{
	pthread_t tid[NO_OF_THREADS];

	//do intializing the semaphore
	sem_init(&my_count,0,3);

	for(int i = 0;i < NO_OF_THREADS;i++)
	{
		pthread_create(&tid[i],NULL,thread,NULL);
	}
	printf("After created all the threads\n");

	//wait for the threads
	for(int i = 0;i < NO_OF_THREADS;i++)
	{
		pthread_join(tid[i],NULL);
	}

	//destroy the semaphore at last
	sem_destroy(&my_count);

	return 0;
}
