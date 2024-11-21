#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[],char *envp[]){
	for(int i=0;i<argc;i++){
		printf("child =%s\n",argv[i]);
		sleep(1);
	}
	return 0;
}

