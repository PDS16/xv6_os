#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <termios.h>
int main()
{

	// make two process which run same
	// program after this instruction
	int pid = fork();
	
	if (pid== 0){
		int my_pid = getpid();
		int my_ppid = getppid();
        	printf("Child : My process ID is:%d\n",my_pid);
        	printf("Child : The parent process ID is:%d\n\n",my_ppid);
        	printf("Child : Check child process state\n\n");
        	printf("Child : Press any key to continue\n\n");
        	getchar();
        	printf("Child : Check child process state again\n\n");
  	}
    // parent process because return value non-zero.
    else
    {
    		int my_pid = getpid();
        	printf("Parent : My process ID is:%d\n",my_pid);
        	printf("Parent : The child process ID is:%d\n",pid);
        	sleep(60);
        	wait(NULL);
        	exit(0);
    }
	return 0;
}

