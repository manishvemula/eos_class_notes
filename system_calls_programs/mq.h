#ifdef __MQ_H
#define __MQ_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include<sys/ipc.h>

#define MQKEY 0X1234
#define ID1 101
#define ID2 201

typedef struct msg{
	long id;
	char data[32];
}msg_t;



#endif
