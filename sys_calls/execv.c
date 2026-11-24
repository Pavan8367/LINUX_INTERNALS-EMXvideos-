#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
printf("Before exec\n");
//execute the cmd line input
execv(argv[1],argv + 2);
printf("After the exec\n");
}

