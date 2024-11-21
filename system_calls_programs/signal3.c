#include <stdio.h>
#include <unistd.h>
#include<signal.h>

void mysig_handler(int s){
	if(s==SIGCHLD){
	printf("int signal is %d\n",s);
	}
	else if(s==SIGCONT){
	printf("cont signal is %d\n",s);
	}
	else if(s==SIGSEGV){
	printf("SEGV signal is %d\n",s);
	_exit(0);
	}
	else{
	printf("signal is %d\n",s);
	}
}
int main() {
    int i = 1;
	signal(SIGINT,mysig_handler);
	signal(SIGCONT,mysig_handler);
	signal(SIGSEGV,mysig_handler);
	signal(SIGCHLD,mysig_handler);
	signal(SIGKILL,mysig_handler);
	signal(SIGSTOP,mysig_handler);
	while(1){
        printf("running: %d\n", i);
        i++;
        sleep(1);
    }
    return 0;
}
