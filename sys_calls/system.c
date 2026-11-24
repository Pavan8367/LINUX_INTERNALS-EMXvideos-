#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Before system\n");
	system("ps -eal");
	printf("After system\n");
	return 0;
}
