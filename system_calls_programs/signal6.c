//to make child and parent run concurrently for 100 sec

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<string.h>

void sigchld_handler(int sig){
		int s;
	waitpid(-1,&s,0);
		printf("child exit status: %d",WEXITSTATUS(s));
}
int main(){
	int ret,ret1,i;
	printf("program started....\n");
	struct sigaction sa,sao;
	sa.sa_handler=sigchld_handler;
	memset(&sa,0,sizeof(struct sigaction));
	ret1=sigaction(SIGCHLD,&sa,&sao);
	if(ret1==-1){
		printf("sigaction failed\n");
	}
	ret=fork();
	if(ret==0){ //child process
		for(i=1;i<=5;i++){
			printf("child->%d\n",i);
			sleep(1);
		}
		_exit(0);
	}
	else{   //parent process
		for(int i=1;i<=10;i++){
			printf("parent->%d\n",i);
			sleep(1);
		}
	}
	printf("program closed..\n");
	return 0;
}

