/**Find max number of child processes that can be created on Linux using C program?
Hint: use fork() in inﬁnite loop (wisely).**/


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
	int i,s,pid;
	int cnt=0;
	while(1){
		pid=fork();
		if(pid==-1){
			printf("fork failed at child count=%d\n",cnt);
			_exit(0);
		}
		else if(pid==0){
			sleep(5);
			_exit(0);
		}
		else{
			cnt++;
			printf("child count=%d\n",cnt);
		}
		//printf("waitpid=%d",ret);
	}
//	waitpid(pid,&s,0);
	return 0;
}
