#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>


int cnt=0;
sem_t s;
void * inc_fn(void * params){
    for(int i=1;i<=100000;i++){
        //lock
        sem_wait(&s);
        cnt++;
        printf("inc:cnt=%d\n",cnt);
        sem_post(&s);
        //sleep(1);
    }
    return NULL;
}

void * dec_fn(void * params){
    
    for(int i=1;i<=100000;i++){
        sem_wait(&s);
        cnt--;
        printf("dec:cnt=%d\n",cnt);
        sem_post(&s);
        //sleep(1);
    }
    return NULL;
}


int main(){
    int ret;
    pthread_t th1,th2;
    ret=sem_init(&s,0,1);
    if(ret<0){
        perror("sem_init fail");
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
    sem_destroy(&s);
    return 0;
}