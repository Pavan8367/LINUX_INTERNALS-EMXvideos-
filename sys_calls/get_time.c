#include<stdio.h>
#include<sys/time.h>

int main()
{
//get the time
struct timeval tv;
gettimeofday(&tv,NULL);

// display the time
printf("%lu\n",tv.tv_sec);//normal time. as time()..
printf("%lu\n",tv.tv_usec);//for micro seconds..
return 0;
}
