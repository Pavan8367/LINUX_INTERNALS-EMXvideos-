#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid = getpid();
	pid_t ppid = getppid();

	printf("child pid = %d\nparent pid = %d\n",pid,ppid);

	return 0;
}
