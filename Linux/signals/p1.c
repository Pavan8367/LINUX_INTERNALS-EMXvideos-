#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
int a,b;

void add(int n)
{
	printf("add result : %d\n",a + b);
}
void sub(int n)
{
	printf("sub result : %d\n",a - b);
}
void mul(int n)
{
	printf("Mul result : %d\n",a * b);
}

void main()
{
	printf("%d-- >\n",getpid());
	printf("Enter the two numbers : ");
	scanf("%d %d",&a,&b);

	signal(1,add);
	signal(2,sub);
	signal(3,mul);
	while(1);
}
