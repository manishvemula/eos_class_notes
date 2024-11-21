#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/sem.h>


typedef struct msg{
	int counter;
}msg_t;

union semun{
      			int              val;    /* Value for SETVAL */
               struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
               unsigned short  *array;  /* Array for GETALL, SETALL */
               struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                           (Linux-specific) */
};



#define SEMKEY 0x4321
#define SMKEY 0x1234

int main(){
	int ret,s;
	int shmid,semid;
	union semun su;
	struct sembuf ops[1];
	msg_t *ptr;
	//create sema with single counter
	semid=semget(SEMKEY,1,IPC_CREAT | 0600);
	if(semid<0){
		perror("semid fail");
	}
	//intial sema count=1
	su.val = 1;
	ret=semctl(semid,0,SETVAL,su);
	if(ret<0){
		perror("semctl fail");
		_exit(1);
	}
	shmid=shmget(SMKEY,sizeof(msg_t),IPC_CREAT | 0640);
	if(shmid<0){
		perror("shmget fail");
		_exit(0);
	}
//	struct sembuf ops[1];
	ptr=shmat(shmid,NULL,0);
	if(ptr==(void *)-1){
		perror("shmat fail");
		shmctl(shmid,IPC_RMID,NULL);
		_exit(2);
	}

	ptr->counter=0;
	ret=fork();
	if(ret==0){
		for(int i=1;i<=1000;i++){
			//P
			ops[0].sem_num=0;
			ops[0].sem_op=-1;
			ops[0].sem_flg=0;
			ret=semop(semid,ops,1);
			ptr->counter--;
			printf("child: %d\n",ptr->counter);
			//V
			ops[0].sem_num=0;
			ops[0].sem_op=+1;
			ops[0].sem_flg=0;
			ret=semop(semid,ops,1);
		}
		shmdt(ptr);
		_exit(0);
	}
	else{
		for(int i=1;i<=1000;i++){
			//P
			ops[0].sem_num=0;
			ops[0].sem_op=-1;
			ops[0].sem_flg=0;
			ret=semop(semid,ops,1);
			ptr->counter++;
			printf("parent: %d\n",ptr->counter);
			//V
			ops[0].sem_num=0;
			ops[0].sem_op=+1;
			ops[0].sem_flg=0;
			ret=semop(semid,ops,1);
		}
		waitpid(ret,&s,0);
		semctl(semid,1,IPC_RMID);
		printf("final count:%d\n",ptr->counter);
//		semctl(semid,1,IPC_RMID);
		shmdt(ptr);
		shmctl(shmid,IPC_RMID,NULL);
	}
	return 0;
}


