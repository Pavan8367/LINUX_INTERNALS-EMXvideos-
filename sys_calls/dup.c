#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main()
{
//open the f1.txt in write mode.
int fd = open("f1.txt",O_WRONLY);

int new_fd = dup(1);

close(1);

dup(fd);

printf("Print this message into FILE\n");
printf("Print this message into STDOUT\n");
printf("hi hello pavan....!\n");

return 0;
}
