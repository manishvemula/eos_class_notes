#include <stdio.h>
#include <unistd.h>
#include<signal.h>

void sigint_handler(int s){
	printf("signal is %d\n",s);
}
void sigcont_handler(int s){
	printf("signal is %d\n",s);
}
void sigstop_handler(int s){
	printf("signal is %d\n",s);
}
void sigchld_handler(int s){
	printf("signal is %d\n",s);
}
void sigkill_handler(int s){
	printf("signal is %d\n",s);
}
int main() {
    int i = 1;
	signal(2,sigint_handler);
	signal(18,sigcont_handler);
	signal(19,sigstop_handler);
	signal(17,sigchld_handler);
	signal(9,sigkill_handler);
	while(1){
        printf("running: %d\n", i);
        i++;
        sleep(1);
    }
    return 0;
}
