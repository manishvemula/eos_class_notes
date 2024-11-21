#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include<unistd.h>
#include<sys/wait.h>
typedef struct msg{
	int counter;
}msg_t;

#define SMKEY 0x1234

int main(){
	int ret,s;
	int shmid;
	shmid=shmget(SMKEY,sizeof(msg_t),IPC_CREAT | 0640);
	if(shmid<0){
		perror("shmget fail");
		_exit(1);
	}
	

	msg_t *p;
	p=shmat(shmid,NULL,0);
	if(p==(void *)-1){
		perror("shmat fail");
		shmctl(shmid,IPC_RMID,NULL);
		_exit(2);
	}

	p->counter=0;
	ret=fork();
	if(ret==0){
		for(int i=1;i<=10;i++){
			p->counter--;
			printf("child: %d\n",p->counter);
			sleep(1);
		}
	}
	else{
		for(int i=1;i<=10;i++){
			p->counter++;
			printf("parent: %d\n",p->counter);
			sleep(1);
		}
		waitpid(ret,&s,0);
		printf("final count:%d\n",p->counter);
		shmdt(p);
		shmctl(shmid,IPC_RMID,NULL);
	}
	return 0;
}


