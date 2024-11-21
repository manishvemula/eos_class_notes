//#include "mq.h"
#include <stdio.h>
   #include <unistd.h>
   #include <sys/wait.h>
   #include <sys/msg.h>
   #include<sys/ipc.h>

 #define MQKEY 0X1234
 #define ID1 101
 #define ID2 201
 
 typedef struct msg{
    long id;
     char data[32];
 }msg_t;
 

int main(){
	
	int ret,mqid;
	mqid=msgget(MQKEY,0);
	if(mqid<0){
		printf("P2:msgget fail");
		_exit(0);
	}
	
	msg_t m2;
	printf("waiting for p1 msg...\n");
	ret=msgrcv(mqid,&m2,sizeof(msg_t)-sizeof(long),ID1,0);
	if(ret<0){
		perror("P2:msgrcv fail");
	}
	else{
		printf("P2: msg recieve=%s",m2.data);
	}

	msg_t m4;
	m4.id=ID2;
	printf("p2: enter a  msg....\n");
	gets(m4.data);
	ret=msgsnd(mqid,&m4,sizeof(msg_t)-sizeof(long),0);
	if(ret<0){
		perror("P2:msgsnd fail");
	}
	else{
		printf("P2: ,msg sent=%s",m4.data);
	}
	return 0;
}
