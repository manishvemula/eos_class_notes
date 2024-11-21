/**From a parent process (A) create a child process (B).
The child (B) in turn creates new child process (C) and it (C) in turn create new child (D).
All these processes should run
concurrently for 5 seconds and cleaned up properly upon termination.**/
//A->B->C->D
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int i,pida,sa,pidb,sb,pidc,sc;
	pida=fork();
	if(pida==0){ //child of A
		
		pidb=fork();
		if(pidb==0){ // child of B->C
			
			pidc=fork();
			if(pidc==0){ //child of C->D
				for(int k=1;k<=5;k++){
					printf("D=%d\n",k);
					sleep(1);
				}
				_exit(0);
			}
			else{ //parent of C->B
				for(int k=1;k<=5;k++){
					printf("C=%d\n",k);
					sleep(1);
				}
				waitpid(pidc,&sc,0);
			}
		}
		else{ //parent of B=> A
			for(int j=1;j<=5;j++){
				printf("B=%d\n",j);
				sleep(1);
			}
			waitpid(pidb,&sb,0);
		}

	}
	else{ //parent A
		for(int i=1;i<=5;i++){
			printf("parent (A)=%d\n",i);
			sleep(1);
		}
		waitpid(pida,&sa,0);
	}
return 0;
}

