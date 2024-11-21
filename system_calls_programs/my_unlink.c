#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>


int main(int argc,char *argv[]){
	int ret= unlink(argv[1]);
	if(ret==-1){
		printf("failed..\n");
		exit(1);
	}
	printf("success....\n");
	return 0;
}



