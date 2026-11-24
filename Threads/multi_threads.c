//multi threads creation for single function....

#include<stdio.h>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>

void *fun1(void *arg)
{
	while(1)
	{
		printf("1\n");
		sleep(1);
	}
}

int main()
{
	//create thread1
	pthread_t tid1,tid2;

	pthread_create(&tid1,NULL,fun1,NULL);

	//create thread2
	pthread_create(&tid2,NULL,fun1,NULL);

	while(1);

	return 0;
}
