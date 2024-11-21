#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	char path[120];
	struct stat s;
	printf("enter file/dir path:");
	scanf("%[^\n]",path);
	int ret=stat(path,&s);
	if(ret==-1){
		perror("stat() failed...\n");
		exit(-1);
	}
	printf("file inode: %lu\n",s.st_ino);
	printf("file size: %lu\n",s.st_size);
	printf("file no. of 512b blockes allocated: %ld\n",s.st_blocks);
	printf("file block size: %lu\n",s.st_blksize);
	printf("file device id: %lu\n",s.st_rdev);
	printf("file uid: %u\n",s.st_uid);
	printf("file gid: %u\n",s.st_gid);
	printf("file hard links no.: %lu\n",s.st_nlink);
	printf("file id of device containing file: %lu\n",s.st_dev);
	printf("file inode: %o\n",s.st_mode);
	
	return 0;
}
