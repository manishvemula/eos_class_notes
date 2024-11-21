#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
int main(){
	int ret,s,arr[2];
	char buf1[32]="hello welcome!",buf2[32];
	ret=pipe(arr);
	if(ret<0){
		perror("pipe() failed");
		_exit(1);
	}
	ret=fork();
	if(ret==0){//child ->writter
	close(arr[0]);
	write(arr[1],buf1,sizeof(buf1));
	printf("child :written to  pipe:%s\n",buf1);
	close(arr[1]);
	}
	else{//parent->reader
	close(arr[1]);	
	read(arr[0],buf2,sizeof(buf2));
	printf("parent:read from pipe:%s\n",buf2);
	waitpid(ret,&s,0);
	close(arr[0]);
	}
	return 0;
}
