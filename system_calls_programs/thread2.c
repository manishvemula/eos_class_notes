#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// multi-threaded program

// step1 : write thread function
void* thread1_func(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("thread1: %d,pid=%d,tid=%d\n", i,getpid(),gettid());
        sleep(1);
    }
    return NULL;
}

void* thread2_func(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("thread2: %d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    int i, ret;
    pthread_t th1, th2;
    // step2 : create thread
    ret = pthread_create(&th1, NULL, thread1_func, NULL);
    ret = pthread_create(&th2, NULL, thread2_func, NULL);
    for(i=1; i<=10; i++) {
        printf("main: %d,pid=%d,tid=%d\n", i,getpid(),gettid());
        sleep(1);
    }
    return 0;
}
