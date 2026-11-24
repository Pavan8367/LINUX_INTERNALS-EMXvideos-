#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include<fcntl.h>
void main()
{
	mkfifo("f1",0664);
	perror("mkfifo");
	mkfifo("f2",0664);
	perror("mkfifo");	
	printf("before open\n");
	int ff=open("f1",O_RDONLY);
	int fd=open("f2",O_WRONLY);
	printf("after open\n");
	if(ff<0)
	{
		perror("open");
		return;
	}
	if(fork()!=0)
	{
		char s[20];
		while(1)
		{
			printf("before read\n");
			read(ff,s,sizeof(s));
			printf("after read\n");
			printf("%s\n",s);
		}
	}
	else
	{
		while(1)
		{
			char s[20];
			printf("enter the string...\n");
			scanf("%s",s);
			write(fd,s,strlen(s));
		}

	}
}

