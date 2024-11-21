#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

void sig_handler(int sig){ //sig handler function
	printf("signal caught: %d and PID=%d \n",sig,getpid());
}

int main(){
	struct sigaction sa;
	int ret;
	//register sig handler using sigaction
	memset(&sa,0,sizeof(struct sigaction));
	sa.sa_handler=sig_handler;

	ret=sigaction(SIGINT,&sa,NULL);
	if(ret<0){
		perror("sigaction failed()");
		_exit(1);
	}
	ret=sigaction(SIGTERM,&sa,NULL);
	if(ret<0){
		perror("sigaction failed()");
		_exit(1);
	}
	sigset_t s;
	printf("wait for SIGINT,SIGALRM,SIGSEGV signals....\n");
	sigfillset(&s);
	sigdelset(&s,SIGINT);
	sigdelset(&s,SIGALRM);
	sigdelset(&s,SIGSEGV);
//	sigdelset(&s,SIGTERM);
	sigsuspend(&s);

	printf("bye!\n");
	return 0;
	}
