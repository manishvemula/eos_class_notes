#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* thread1_fn(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("thread1: %d\n", i);
        sleep(1);
    }
    return NULL;
}


void* thread2_fn(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("thread2: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void* thread3_fn(void *param) {
    int i;
    for(i=1; i<=10; i++) {
        printf("thread3: %d\n", i);
        sleep(1);
        if(i==3)
            fork();
    }
    return NULL;
}

int main() {
    pthread_t th1, th2, th3;
    int i, ret;

    ret = pthread_create(&th1, NULL, thread1_fn, NULL);
    ret = pthread_create(&th2, NULL, thread2_fn, NULL);
    ret = pthread_create(&th3, NULL, thread3_fn, NULL);
    for(i=1; i<=10; i++) {
        printf("main: %d\n", i);
        sleep(1);
    }
    return 0;
}
