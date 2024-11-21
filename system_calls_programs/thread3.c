#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void* t1_fun(void* param){
	int i,*num=(int *)param;
	for(int i=1;i<=10;i++){
		printf("%d * %d = %d\n",*num,i,*num * i);
		sleep(1);
	}
	return NULL;
}

int main(){
	int n1=10,n2=1,n3=90,n4=54;
	pthread_t t1,t2,t3,t4;
	
	pthread_create(&t1,NULL,t1_fun,&n1);
	pthread_create(&t2,NULL,t1_fun,&n2);
	pthread_create(&t3,NULL,t1_fun,&n3);
	pthread_create(&t4,NULL,t1_fun,&n4);
	printf("press enter to exit...\n");
    getchar();
	
	return 0;
}
