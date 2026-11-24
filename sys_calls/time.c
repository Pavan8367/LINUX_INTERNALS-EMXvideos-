#include<stdio.h>
#include<time.h>
int main()
{
	//to get the time.proto type from man page...
	time_t my_time = time(NULL);
	printf("Time is : %lu\n",my_time);
}
