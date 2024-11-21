#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

/**
 * declare mutex
 * init mutex
 * lock mutex
 * unlock mutex
 * destroy mutex
 * 
 */
int cnt=0;
pthread_mutex_t m;
void * inc_fn(void * params){
    for(int i=1;i<=100000;i++){
        //lock
        pthread_mutex_lock(&m);
        cnt++;
        printf("inc:cnt=%d\n",cnt);
        pthread_mutex_unlock(&m);
        //sleep(1);
    }
    return NULL;
}

void * dec_fn(void * params){
    
    for(int i=1;i<=100000;i++){
        pthread_mutex_lock(&m);
        cnt--;
        printf("dec:cnt=%d\n",cnt);
        pthread_mutex_unlock(&m);
        //sleep(1);
    }
    return NULL;
}


int main(){
    int ret;
    pthread_t th1,th2;
    ret=pthread_mutex_init(&m,NULL);
    if(ret<0){
        perror("pthread_mutex_init fail");
        _exit(1);
    }
    ret=pthread_create(&th1,NULL,inc_fn,NULL);
    ret=pthread_create(&th2,NULL,dec_fn,NULL);
    if(ret!=0){
        perror("pthread_create fail\n");
    }
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    printf("final count=%d",cnt);
    pthread_mutex_destroy(&m);
    return 0;
}