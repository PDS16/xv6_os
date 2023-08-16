#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    signal(SIGINT,SIG_IGN);
    signal(SIGTERM,SIG_IGN);
    printf("Process Id is: %d\n",getpid());
    while(1)
    {   
        printf("WAITING...\n");
        sleep(3);
    }

    return 0;
}



