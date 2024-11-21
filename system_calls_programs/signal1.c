#include <stdio.h>
#include <unistd.h>
#include<signal.h>

void sigint_handler(int s){
	printf("signal is %d\n",s);
}
int main() {
    int i = 1;
	signal(9,sigint_handler);
    while(1) {
        printf("running: %d\n", i);
        i++;
        sleep(1);
    }
    return 0;
}
