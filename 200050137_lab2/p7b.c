#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{	
int n ;
scanf("%d",&n);
	printf("Parent is : %d\n",getpid());
	printf("Number of children: %d\n",n);
	for(int i=0;i<n;i++) // loop will run n times (n=5)
	{
		if(fork() == 0)
		{
			printf("Child %d is created\n",getpid());
			sleep(1);
			printf("Child %d of parent %d exited\n",getpid(),getppid());
			exit(0);
		}
	}
	for(int i=0;i<n;i++) // loop will run n times (n=5)
	wait(NULL);
	
}

