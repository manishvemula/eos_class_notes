#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int ret;
	printf("program started....\n");
	ret=fork();
	if(ret==0){//child process
		printf("c->fork returned=%d\n",ret);
		printf("c->child's pid=%d\n",getpid);
		printf("c->child's parent pid=%d\n",getppid);
	}
	else{ //parent process	
		printf("p->fork returned=%d\n",ret);
		printf("p->parent's pid=%d\n",getpid);
		printf("p->parent's parent pid=%d\n",getppid);
	}
	printf("program closed..\n");
	return 0;
	}

