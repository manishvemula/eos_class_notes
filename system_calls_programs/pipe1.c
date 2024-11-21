#include<unistd.h>
#include<stdio.h>

int main(){
	int ret,arr[2];
	char buf1[32]="hello welcome!",buf2[32];
	ret=pipe(arr);
	if(ret<0){
		perror("pipe() failed");
		_exit(1);
	}
	write(arr[1],buf1,sizeof(buf1));
	printf("written to pipe:%s\n",buf1);
	read(arr[0],buf2,sizeof(buf2));
	printf("read from pipe:%s\n",buf2);
	close(arr[1]);
	close(arr[0]);
	return 0;
	}
