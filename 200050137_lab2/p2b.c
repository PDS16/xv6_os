#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{

	int n;
	scanf("%d",&n); 
	int pid = fork();
	
	if (pid== 0){
		int x = 1;
		int my_pid = getpid();
		while(x<n+1)
		{
			printf("C %d %d\n",my_pid,x);
			x++;
		}
  	}
    else
    {		
    		wait(NULL);
    		int x = 2*n;
    		int my_pid = getpid();
        	while(n<x)
		{
			n++;
			printf("P %d %d\n",my_pid,n);
		}
    }
	return 0;
}

