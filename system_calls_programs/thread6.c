#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

pid_t gettid(void);

void* th_fun1(void *param){
    int i;
    for(i=1;i<=100;i++){
        printf("thread:%d,pid=%d,tid=%d\n",i,getpid(),gettid());
        sleep(1);
    }
    return NULL;
}

void sigint_handler(int sig){
    printf("siganal caught:%d,pid=%d,tid=%d\n",sig,getpid(),gettid());
    if(gettid()==getpid()){
        _exit(0);
    }
    else{
       // printf("Hi\n");
        pthread_exit(NULL);
    }
}
int main(){
    pthread_t th1;
    //pthread_create(&th1,NULL,th_fun1,NULL);
    int ret;
    struct sigaction sa;
    memset(&sa,0,sizeof(sa));
    sa.sa_handler=sigint_handler;
    ret=sigaction(SIGINT,&sa,NULL);

    ret=pthread_create(&th1,NULL,th_fun1,NULL);
    if(ret!=0){
        perror("pthread_create fail");
        _exit(1);
    }
    printf("enter press for signal to thread\n");
    getchar();
    pthread_kill(th1,SIGINT);
    printf("enter press for exit from prog\n");
    getchar();
    return 0;
}
