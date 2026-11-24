#include<stdio.h>
#include<unistd.h>

int main()
{
printf("Before exec\n");

//execlp("ls","ls","-l",NULL);
execlp("date","date",NULL);
printf("After the exec\n");
}

