#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <signal.h>
#include<sys/wait.h>

#define SOCK_FILE   "/tmp/mysock"

void strupr(char *s){
	while(*s){
		*s =( *s >= 'a' && *s<='z') ? *s-32 : *s;
		*s++;
	}
}

int serv_fd;

void sigint_handler(int sig){
	//13.shutdown
	shutdown(serv_fd,SHUT_RDWR);
	//14.unlink
	unlink(SOCK_FILE);
	_exit(0);
}

void sigchld_handler(int sig){
	int s;
	waitpid(-1,&s,0);
}

int main() {
    int ret, cli_fd;
	char msg[512];
    struct sockaddr_un serv_addr, cli_addr;
    socklen_t socklen = sizeof(cli_addr);
	
    struct sigaction sa;
	memset(&sa,0,sizeof(sa));
	ret=sigaction(SIGINT,&sa,NULL);	
	sa.sa_handler=sigint_handler;
	ret=sigaction(SIGCHLD,&sa,NULL);
	sa.sa_handler=sigchld_handler;
    //1. create server socket
    serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    //2. bind the address
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, SOCK_FILE);
    ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    //3. listen to server socket
    listen(serv_fd, 5);
    while(1) {
        //6. accept client connection
        cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
        ret=fork();
		if(ret==0){
			do{
		//8. read data from client
        		read(cli_fd, msg, sizeof(msg));
//        		printf("client: %s\n", msg);
        //9. send data to client
        		strupr(msg);
        		write(cli_fd, msg, strlen(msg)+1);
			}while(strcmp(msg,"exit")!=0);
        //12. close client socket
        close(cli_fd);
		}
		else{
			close(cli_fd);
		}
    }
    return 0;
}

