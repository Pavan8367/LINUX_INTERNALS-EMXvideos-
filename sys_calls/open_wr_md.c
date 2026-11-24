#if 0

#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd = open("f3.txt",O_WRONLY | O_CREAT,0644);

	if(fd == -1)
	{
		perror("open");
		return -1;
	}

	printf("FD = %d\n",fd); 
	return 0;
}

#endif

#if 0

//O_EXCL is used to if the file is already exists then you again open that it will through a error namely --> open: File exists

#include<stdio.h>
#include<fcntl.h> 
int main()
{
         int fd = open("f4.txt",O_WRONLY | O_CREAT | O_EXCL,0644);
 
         if(fd == -1)
         {
                 perror("open");
                 return -1;
         }
 
         printf("FD = %d\n",fd); 
         return 0;
}

#endif

#if 1
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
	int fd = open("f3.txt",O_WRONLY);

	if(fd == -1)
	{
		if(errno == EACCES)
		{
			printf("ERROR : The request access is not allowed\n");
		}
		else if(errno == EEXIST)
		{
			printf("ERROR : The file already exists\n");
		}
		return -1;
	}

	printf("FD = %d\n",fd); 
	return 0;
}

#endif
