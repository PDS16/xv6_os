#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

int account_balance = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* increment(void *eachDeposit) {
    
    int x = *(int *)eachDeposit;
    int temp = 0;
    for (int i = 0; i < x*1000000; i++) {
        temp++;
    }
    pthread_mutex_lock(&lock);
    account_balance+= temp;
    pthread_mutex_unlock(&lock);
    
}

int main(int argc, char* argv[]) {

    if ( argc != 2)
    {
        printf("Usage: Exactly one command line argumengt required\n");
        return 0;
    }

    clock_t t;
    t = clock();

    int threadNum = atoi(argv[1]);
    pthread_t th[threadNum];
    int i;
    int eachDeposit = 2048/threadNum;

    for (i = 0; i < threadNum; i++) {
        if (pthread_create(th + i, NULL, &increment, &eachDeposit) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        printf("Transaction %d has started\n", i);
    }
    for (i = 0; i < threadNum; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }
        printf("Transaction %d has finished\n", i);
    }
    printf("Account Balance is : %d\n", account_balance);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC*1000;\
    printf("Time spent: %f ms", time_taken);

    return 0;
}