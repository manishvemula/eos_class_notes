#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int i,ret,err,s;
	printf("program started\n");
	ret=fork();
	if(ret==-1){
		printf("fork is failed\n");
		_exit(0);
	}
	else if(ret==0){
		err=execl("/snap/bin/firefox","firefox","linkedin.com",NULL);
		if(err<0){
			printf("exec() failed\n");
			_exit(1);
		}
	}
	else{
		printf("exit status:%d\n",WEXITSTATUS(s));
		waitpid(-1,&s,0);
	}
	printf("program finish\n");
	return 0;
}
