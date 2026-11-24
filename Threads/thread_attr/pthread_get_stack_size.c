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
size_t size;

	pthread_t tid;
	pthread_attr_init(&my_attr);

	//change the dettach state
	pthread_attr_setstacksize(&my_attr,16383); //base size of stack size is 16384 bytes,while setting if you decrease even one byte it takes the default size as 8388608. 
	pthread_attr_getstacksize(&my_attr,&size);

	printf("Stack Size = %ld\n",size); //default stack size is ---->  8388608


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
