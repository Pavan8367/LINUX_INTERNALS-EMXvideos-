#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>

void main(int argc,char **argv)
{
if(argv < 3)
{
printf("Arguements are less..\n");
return;
}
kill(atoi argv[2],atoi argv[1]);
perror("kill");
}
