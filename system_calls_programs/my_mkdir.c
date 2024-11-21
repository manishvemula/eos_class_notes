#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc,char *argv[]){
	int ret= mkdir(argv[1],0644);
	if(ret==-1){
		printf("fail...\n");
		exit(1);
	}
	printf("success\n");
	return 0;
}



