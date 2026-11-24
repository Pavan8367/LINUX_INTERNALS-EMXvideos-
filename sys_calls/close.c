#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main()
{
//open the file f1.txt in read mode
int fd1 = open("f1.txt",O_RDONLY);
printf("fd --> %d\n",fd1);

//closing file descriptor
close(fd1);

int fd2 = open("f2.txt",O_RDONLY);
printf("fd --> %d\n",fd2);
}
