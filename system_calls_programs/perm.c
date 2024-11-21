//to give permissions to file through system call


#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	int ret;
	ret=chmod(argv[1],0777);
	if(ret!=0){
		printf("chmod command fail");
		exit(1);
	}
	printf("successfully changed permisiion......");
	return 0;
}

