#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t my_lock;
int count;
void *threads(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&my_lock);
		count = 0;
		count += 5;
		count += 14;
		printf("%d\n",count);
		//pthread_mutex_unlock(&my_lock); --> if the mutex is already locked by anothrer thread, pthread_mutex_lock suspends the calling thread until the mutex is unlocked.
	}
}
int main()
{
	pthread_t tid1,tid2;
	pthread_mutex_init(&my_lock,NULL);
	//creating threads
	pthread_create(&tid1,NULL,threads,NULL);
	pthread_create(&tid2,NULL,threads,NULL);

	//waiting for the thread
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_mutex_destroy(&my_lock);
}
