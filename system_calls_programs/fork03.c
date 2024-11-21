//to make child and parent run concurrently for 100 sec

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int ret,i;
	printf("program started....\n");
	ret=fork();
	if(ret==0){ //child process
		for(i=1;i<=10;i++){
			printf("child->%d\n",i);
			sleep(1);
		}
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

