#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pid_t gettid(void);

void* fun_t1(void *param){
    int i;
    for(i=1;i<=10;i++){
        printf("thread1: %d and pid=%d,tid=%d\n",i,getpid(),gettid());
        sleep(1);
    }
    return NULL;
}


int main(){
    int ret,i;
    pthread_t th1;
    pthread_attr_t attr_th1;
    pthread_attr_init(&attr_th1);
    ret=pthread_create(&th1,&attr_th1,fun_t1,NULL);
    if(ret!=0){
        perror("pthread_create fail");
        _exit(1);
    }
    for(i=1;i<=10;i++){
        printf("main: %d and pid=%d,tid=%d\n",i,getpid(),gettid());
        sleep(1);
    }
    printf("enter press to exit");
    getchar();
    pthread_cancel(th1);
    ret=pthread_attr_destroy(&attr_th1);
    if(ret!=0){
        perror("pthread_attr_destroy fail");
    }
    

    return 0;
}