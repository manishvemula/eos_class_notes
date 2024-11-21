/*** write a program (similar to shell) that will execute a new program
("ls -l /home /xyz") so that new program will output to out.txt,
error to err.txt, and read input from in.txt.***/


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(){
	int err,pid,fd1,fd2,s;
	printf("parent started\n");
	pid=fork();
	if(pid==0){
		fd1=open("out.txt",O_CREAT | O_TRUNC | O_WRONLY,0644);
		if(fd1<0){
			perror("fd1 fail");
			_exit(0);
		}
		close(1);
		dup(fd1);
		close(fd1);

		fd2=open("err.txt",O_CREAT | O_TRUNC | O_WRONLY,0644);
		if(fd2<0){
			perror("fd2 fail");
			_exit(0);
		}
		close(2);
		dup(fd2);
		close(fd2);
		err=execlp("ls","ls","-l","/home","/xyz",NULL);
		if(err<0){
			perror("exec fail");
			_exit(0);
		}
		
	}
	else
		waitpid(pid,&s,0);
	printf("Bye!");
	return 0;
}
