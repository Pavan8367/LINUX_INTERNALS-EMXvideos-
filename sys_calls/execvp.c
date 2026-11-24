#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
printf("Before exec\n");
//execute the cmd line input
execvp(argv[1],argv + 1);
printf("After the exec\n");
}

