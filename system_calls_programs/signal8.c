//to make child and parent run concurrently for 100 sec

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<string.h>

void sigchld_handler(int sig){
		printf("signal caught: %d,pid=%d\n",sig,getpid());
}
int main(){
	int ret,ret1,i;
	sigset_t s;
	printf("program started....\n");
	sigemptyset(&s);
	sigaddset(&s,SIGTERM);
	sigaddset(&s,SIGALRM);
	ret= sigprocmask(SIG_SETMASK,&s,NULL);
	if(ret==-1){
		printf("sigprocmask fail\n");
		_exit(1);
	}
	struct sigaction sa;
	sa.sa_handler=sigchld_handler;
	memset(&sa,0,sizeof(struct sigaction));
	ret1=sigaction(SIGCHLD,&sa,NULL);
	if(ret1==-1){
		printf("sigaction failed\n");
		_exit(0);
	}
	i=0;
	while(1){
		printf("running : %d and pid=%d\n",i++,getpid());
		sleep(1);
	}
	printf("program closed..\n");
	return 0;
}

