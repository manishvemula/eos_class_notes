//code for dir operations -> opendir,readdir,close


#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
	DIR *dp;
	dp=opendir(argv[1]);
	printf("argc=%d",argc);
        if(dp==NULL){
		printf("opendir failed...\n");
		exit(1);
	}
	else{
		printf("opend\n");
	}

	struct dirent *ent;
	
	while((ent=readdir(dp))!=NULL){
		printf("inode= %ld\n",ent->d_ino);
		printf("name= %s \n",ent->d_name);
	}
	int ret= closedir(dp);
	if(ret==0){
		printf("closed successfully...\n");
        }
	else{
		printf("not closed......\n");
	}
	return 0;
}
	


