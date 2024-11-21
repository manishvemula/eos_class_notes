#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int ret=link(argv[1],argv[2]);
	printf("argc=%d\n",argc);
	if(ret==-1){
		printf("failed.......\n");
		exit(1);
	}
	printf("successfull......\n");
	return 0;
}


