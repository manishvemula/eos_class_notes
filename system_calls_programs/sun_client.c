//sun_client

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCK_FILE   "/tmp/mysock"

int main(){
	int ret, cli_fd;
    struct sockaddr_un serv_addr;
    char msg[512];
	//4.socket
	cli_fd=socket(AF_UNIX,SOCK_STREAM,0);
	//5.create
	serv_addr.sun_family=AF_UNIX;
	strcpy(serv_addr.sun_path,SOCK_FILE);
	ret=connect(cli_fd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
	do{

	//7.write
		printf("client: ");
		gets(msg);
		write(cli_fd,msg,strlen(msg)+1);
	//10.read
		read(cli_fd,msg,sizeof(msg));
		printf("server: %s\n",msg);
	}while(strcmp(msg,"bye")!=0);
	//11.close
	close(cli_fd);
	return 0;
}
