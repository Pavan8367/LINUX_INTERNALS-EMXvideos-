#include<stdio.h>
#include<unistd.h>

int main()
{
printf("Before exec\n");

//execute the "ls" file
//execl("/bin/ls","ls",NULL);

//execl("/bin/ls","ls","-l",NULL);
//execl("/bin/date","date",NULL);

printf("After the exec\n");
}

