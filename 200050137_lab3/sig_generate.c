#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char* argv[])
{
    int pid = atoi(argv[1]);

    // printf("SENDING SIGINT TO PROCESS -> %d...\n",pid);
    kill(pid,SIGINT);
    // sleep(2);
    // printf("SENDING SIGTERM TO PROCESS -> %d...\n",pid);
    kill(pid,SIGTERM);
    // sleep(2);
    // printf("SENDING SIGKILL TO PROCESS -> %d...\n",pid);
    kill(pid,SIGKILL);
}



