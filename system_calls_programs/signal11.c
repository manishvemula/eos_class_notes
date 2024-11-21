#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<unistd.h>

void sig_handler(int sig){ //sig handler function
	for(int i=1;i<=5;i++){
		printf("signal caught: %d and PID=%d \n",sig,getpid());
		sleep(1);
		}
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
	//sigset_t s;
	sigfillset(&sa.sa_mask);
	for(int i=1; ;i++){
		printf("running :%d \n",i);
		sleep(1);
	}
	printf("bye!\n");
	return 0;
	}
