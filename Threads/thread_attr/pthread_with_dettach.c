#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

//create object for the attribute
pthread_attr_t my_attr;

void *thread(void *arg)
{
	for(int i = 0;i < 10;sleep(1),i++)
	{
		printf("In thread ---> %d\n",i+1);
	}
}

int main()
{
	pthread_t tid;
	pthread_attr_init(&my_attr);

	//change the dettach state
	pthread_attr_setdetachstate(&my_attr,PTHREAD_CREATE_DETACHED);

	//create pthread
	pthread_create(&tid,&my_attr,thread,NULL);

	//wait for the pthread join
	pthread_join(tid,NULL);
	//wait for the pthread
	printf("After pthread_join\n");

	for(int i = 0;i<10;sleep(1),i++)
	{
		printf("In main ---> %d\n",i+1);
	}

	//destroying the attribute
	pthread_attr_destroy(&my_attr);

	return 0;
}
