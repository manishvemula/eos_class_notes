#include <unistd.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <sys/msg.h>
#include<stdio.h>

#define MQKEY 0x1234

typedef struct msg{
	long id;
	char data[32];
}msg_t;

int main(){
	int ret,pid,s,mqid;
	mqid=msgget(MQKEY,IPC_CREAT | 0600);
	if(mqid<0){
		perror("mqid fail");
		_exit(1);
	}
	pid=fork();
	if(pid==0){
		msg_t m1;
		m1.id=101;
		printf("child enters msg:\n");
		gets(m1.data);
		ret=msgsnd(mqid,&m1,sizeof(msg_t)-sizeof(long),0);
		if(ret<0){
			perror("msgsnd fail");
			_exit(1);
		}
		else{
			printf("msg sent by child\n");
		}
	}
	else{
		msg_t m2;
		printf("parent waiting for child msg....\n");
		ret=msgrcv(mqid,&m2,sizeof(msg_t)-sizeof(long),101,0);
		if(ret<0){
			perror("msgsnd fail");
			_exit(1);
		}
		else{
			printf("parent recieved from child : %s\n",m2.data);
		}
		waitpid(-1,&s,0);
	    msgctl(mqid,IPC_RMID,NULL);
	}
	return 0;
}
