#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char *argv[]){
	int fs,fd;
	fs=open(argv[1] , O_RDONLY);
	if(fs==-1){
		perror("error in opening\n");
		exit(-1);
	}

	fd=open(argv[2], O_CREAT | O_WRONLY , 0644);
	if(fd==-1){
                perror("error in opening\n");
                exit(-1);
        }

	int cnt;
	char buff[19];
	while((cnt=read(fs, buff , sizeof(buff)))!=0){
		printf("%d is cnt\n",cnt);
		write(fd,buff,cnt);
		
	}
	close(fd);
	close(fs);
	printf("completed successfully...\n");
	return 0;
}








