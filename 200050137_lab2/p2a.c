#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

	int n;
	scanf("%d",&n); 
	int pid = fork();
	
	if (pid== 0){
		int my_pid = getpid();
		while(n>0)
		{
			printf("C %d %d\n",my_pid,n);
			n--;
		}
  	}
    else
    {		
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

