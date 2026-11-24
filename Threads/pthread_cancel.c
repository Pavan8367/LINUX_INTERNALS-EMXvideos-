#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void *thread(void *arg)  //thread function
{
	//change the thread cancellation state
	//pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);

	//changing the thread cancellation type (Actually the pthread_cancel is by default enable state and diffred type.but here i am changing																the type to aynchronous).

	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);

	/*for(int i = 0;i < 10;sleep(1),i++)
	  {
	  printf("In thread, %d times\n",i+1);
	  }*/
	while(1);
}
int main()
{
	pthread_t tid;
	//create thread
	pthread_create(&tid,NULL,thread,NULL);
	sleep(3);

	//sending cancelation req
	printf("sending the cancellation request\n");
	pthread_cancel(tid);

	//wait for the pthread
	pthread_join(tid,NULL);


	return 0;
}
