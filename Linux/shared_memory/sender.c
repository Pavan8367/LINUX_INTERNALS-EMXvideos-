#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	// create shm..
	int shmid = shmget('A',100,IPC_CREAT | 0644);

	//Attach the process to shm
	char *ptr = shmat(shmid,0,0);

	//read the string from the user
	char buf[100];
	printf("Enter the string:");
	scanf("%[^\n]",buf);

	//send to string SHM
	strcpy(ptr,buf);

	//dettach the process from shm
	shmdt(ptr);
	return 0;
}
