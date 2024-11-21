//to make child and parent run concurrently for 100 sec

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int ret,i;
	printf("program started....\n");
	ret=fork();
	if(ret==0){ //child process
		for(i=1;i<=100;i++){
			printf("child->%d\n",i);
		}
	}
	else{
		for(int i=1;i<=100;i++){
			printf("parent->%d\n",i);
		}
	}
	printf("program closed..\n");
	return 0;
}

