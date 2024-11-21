/**From one parent create 5 child processes. Each child should run for 5 seconds and 
print count along with its pid. Parent should wait for all child processes
to complete and clean all of them. Hint: use loop to fork() multiple child processes.**/

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){
	int i,s,pid;
	int cnt=0;
	for(i=1;i<=5;i++){
		pid=fork();
		if(pid==0){
			cnt++;
			printf("child-%d parent's pid(%d) and it's pid(%d)\n",cnt,getppid(),getpid());
			//sleep(5);
			_exit(0);
		}
		else{
			cnt++;
		    printf("parent created with child-%d with pid=%d\n",i,pid);
		}
		waitpid(pid,&s,0);
	}
	
return 0;
}
