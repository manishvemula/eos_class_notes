#include<stdio.h>
#include<stdlib.h>

#include <unistd.h>
int main(int argc,char *argv[]){
       int ret=rmdir(argv[1]);
       if(ret==-1){
	       printf("fail...\n");
	}
       printf("success...\n");
       return 0;
      }

