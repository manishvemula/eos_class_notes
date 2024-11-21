#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct input {
    int num;
    int den;
};
struct output {
    int quo;
    int rem;
    int err;
};

void* divide(void *param) {
    struct input *ip = (struct input *)param;
    struct output *op = (struct output *)malloc(sizeof(struct output));
    if(ip->den == 0) {
        printf("divide: divide by zero error\n");
        op->err = 1;
        // terminate the current thread and return given result
        pthread_exit(op);
    }
    op->quo = ip->num / ip->den;
    op->rem = ip->num % ip->den;
    op->err = 0;
    printf("divide: quotient=%d\n", op->quo);
    printf("divide: remainder=%d\n", op->rem);
    //sleep(5);
    return op;
}

int main() {
    pthread_t th;
    struct input in = { .num = 22, .den=7 };
    //struct input in = { .num = 22, .den=0 };
    struct output *out;
    pthread_create(&th, NULL, divide, &in);
    // pthread_join() pause execution of current thread for the completion
    //  of given thread (arg1) and collect its result in out param (arg2).
    pthread_join(th, (void**)&out);
    if(out->err == 0) {
        printf("main: quotient=%d\n", out->quo);
        printf("main: remainder=%d\n", out->rem);
    }
    else
        printf("main: divide by zero error\n");
    free(out);
    return 0;
}
