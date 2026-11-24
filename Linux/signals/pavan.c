#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>

void main()
{
int pid = getpid();
int ppid = getppid();

printf("pid = %d\n",pid);
printf("ppid = %d\n",ppid);
}
