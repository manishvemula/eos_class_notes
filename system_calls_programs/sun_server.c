//sun_server
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/un.h>
#include<string.h>

#define SOCK_FILE   "/tmp/mysock"

int main(){
	int ret,serv_fd,cli_fd;
	struct sockaddr_un serv_addr,cli_addr;
	socklen_t socklen=sizeof(cli_addr);
	char msg[512];
	//1.socket
	serv_fd=socket(AF_UNIX,SOCK_STREAM,0);
	//2.bind
	serv_addr.sun_family=AF_UNIX;
	strcpy(serv_addr.sun_path,SOCK_FILE);
	ret=bind(serv_fd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

	//3.listen
	listen(serv_fd,5);

	//6.accept
	cli_fd=accept(serv_fd,(struct sockaddr*)&cli_addr,&socklen);
	do{
	//8.read
		read(cli_fd,msg,sizeof(msg));
		printf("client: %s\n",msg);
	//9.write
		printf("server: ");
		gets(msg);
		write(cli_fd,msg,strlen(msg)+1);
	}while(strcmp(msg,"bye")!=0);

	//12.close
	close(cli_fd);
	//13.shutdown
	shutdown(serv_fd,SHUT_RDWR);
	//14.unlink
	unlink(SOCK_FILE);
	return 0;
}
