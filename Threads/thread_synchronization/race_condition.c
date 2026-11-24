#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int count;

void *threads(void *arg)
{
	while(1)
	{
		count = 0;
		count += 5;
		count += 14;
		printf("%d\n",count);
	}
}
int main()
{
	pthread_t tid1,tid2;

	//creating threads
	pthread_create(&tid1,NULL,threads,NULL);
	pthread_create(&tid2,NULL,threads,NULL);

	//waiting for the thread
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}
