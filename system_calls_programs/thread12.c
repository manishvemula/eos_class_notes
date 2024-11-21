#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int cnt = 0;
pthread_mutex_t m;

void* incr_thread(void *param) {
    int i;
    for (int i = 0; i <= 10; i++) {
        // lock mutex
        pthread_mutex_lock(&m);
        cnt++;
        printf("incr: %d\n", cnt);
        // unlock mutex
        pthread_mutex_unlock(&m);
        //sleep(1);
    }
    return NULL;
}


void* decr_thread(void *param) {
    int i;
    for (int i = 0; i <= 10; i++) {
        // lock mutex
        pthread_mutex_lock(&m);
        cnt--;
        // unlock mutex
        pthread_mutex_unlock(&m);
        printf("decr: %d\n", cnt);
        //sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t it, dt;
    pthread_mutexattr_t ma;
    // initialize mutex
    pthread_mutexattr_init(&ma);
    #ifdef DEBUG
        printf("using error checking mutex during develoment.\n");
        pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_ERRORCHECK);
    #else
        printf("using normal mutex for production.\n");
        pthread_mutexattr_settype(&ma, PTHREAD_MUTEX_NORMAL);
    #endif
    pthread_mutex_init(&m, &ma);
    pthread_create(&it, NULL, incr_thread, NULL);
    pthread_create(&dt, NULL, decr_thread, NULL);
    pthread_join(it, NULL);
    pthread_join(dt, NULL);
    printf("final count: %d\n", cnt);
    pthread_mutexattr_destroy(&ma);
    // destroy the mutex
    pthread_mutex_destroy(&m);
    return 0;
}