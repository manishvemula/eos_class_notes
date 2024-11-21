#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(){
	char buff[50];	
        getcwd(buff,sizeof(buff));
	printf("current path:%s \n",buff);
	int ret=chdir("/home/manish/desd/eos/");
	if(ret==-1){
		perror("chdir failed....\n");
		exit(-1);
	}
	printf("present working dir is changed..\n");
	getcwd(buff,sizeof(buff));
	printf("pwd=%s\n",buff);
	return 0;
}
