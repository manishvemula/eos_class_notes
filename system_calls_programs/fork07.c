//make child runs for 5 sec and parent for 10sec-----> zombie process
//waitpid() system call

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
	int ret,i,s;
	printf("program started....\n");
	ret=fork();
	if(ret==0){ //child process
		for(i=1;i<=5;i++){
			printf("child->%d\n",i);
			sleep(1);
		}
		_exit(9);
	}
	else{   //parent process
		for(int i=1;i<=10;i++){
			printf("parent->%d\n",i);
			sleep(1);
			if(i==5){
			waitpid(ret,&s,0);
			printf("child exit status=%d\n",WEXITSTATUS(s));
		}
		}
	}
	printf("program closed..\n");
	return 0;
}

