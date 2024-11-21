//#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
//main thread(single threaded process)----------------------------------------------------------
int main(){
	int i;
	for(i=1;i<=10;i++){
		printf("main :%d and pid=%d and tid=%d\n",i,getpid(),getgid());
		sleep(1);
	}
	return 0;
}
