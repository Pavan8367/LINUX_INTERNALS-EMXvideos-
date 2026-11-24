#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	//get the shm id
	int shmid = shmget('A',100,0644);

	//Attach the process
	char *ptr = shmat(shmid,0,0);

	//read string from shm
	char buf[100];
	strcpy(buf,ptr);

	//print the data
	printf("Data --> %s\n",buf);

	//print some info of shm
	struct shmid_ds info;
	shmctl(shmid,IPC_STAT,&info);
	printf("Size of shm -> %lu\n",info.shm_segsz);
	printf("No of attaches -> %lu\n",info.shm_nattch);

	//dettach the process from shm
	shmdt(ptr);

	//delete the SHM
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
