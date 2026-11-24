/*METHOD 1 (By taking the sum as global variable) --> it is ok for one thread to one fun() if 2 threads are created for
						      one function the one thread updated val can overwrite by another one*/ 

#include<stdio.h>
#include<fcntl.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#if 0
int sum;

typedef struct
{
	int start;
	int end;
	int *ptr;
}struct_t;

void *arr_sum(void *arg)
{

	struct_t *lptr = (struct_t*)arg;
	for(int i = lptr -> start;i <= lptr -> end;sleep(1),i++)
		sum += lptr -> ptr[i];

	return NULL;
}
int main()
{
	pthread_t tid;

	int arr[] = {1,2,3,4,5,6,7,8,9,10};

	struct_t var;

	var.start = 0;
	var.end = 9;
	var.ptr = arr;

	pthread_create(&tid,NULL,arr_sum,&var);

	//wait for the pthread
	pthread_join(tid,NULL);

	printf("Sum = %d\n",sum);
	return 0;

}
#endif

/*Method - 2 by using dynamic memory*/

#if 0

typedef struct
{
	int start;
	int end;
	int *ptr;
}struct_t;

void *arr_sum(void *arg)
{
	int *sum = malloc(4);

	struct_t *lptr = (struct_t*)arg;
	for(int i = lptr -> start;i <= lptr -> end;sleep(1),i++)
		*sum += lptr -> ptr[i];

	return (void*)sum;
}
int main()
{
	pthread_t tid;

	int arr[] = {1,2,3,4,5,6,7,8,9,10},*sum;

	struct_t var;

	var.start = 0;
	var.end = 9;
	var.ptr = arr;

	pthread_create(&tid,NULL,arr_sum,&var);

	//wait for the pthread
	pthread_join(tid,(void **)&sum);

	printf("Sum = %d\n",*sum);
	return 0;

}
#endif

/*METHOD 3 --> by using local variable as sum*/
typedef struct
{
	int start;
	int end;
	int *ptr;
}struct_t;

void *arr_sum(void *arg)
{
	int sum = 0;
	struct_t *lptr = (struct_t*)arg;
	for(int i = lptr -> start;i <= lptr -> end;sleep(1),i++)
		sum += lptr -> ptr[i];

	return (void*)(long)sum;/*here 1st typecast into long because int is 4 bytes but (void *) is 8 bytes so long have cap 8 bytes so i typecast
									to long*/
}
int main()
{
	pthread_t tid;

	int arr[] = {1,2,3,4,5,6,7,8,9,10},sum;

	struct_t var;

	var.start = 0;
	var.end = 9;
	var.ptr = arr;

	pthread_create(&tid,NULL,arr_sum,&var);

	//wait for the pthread
	pthread_join(tid,(void **)&sum);

	printf("Sum = %d\n",sum);
	return 0;

}

