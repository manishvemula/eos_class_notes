#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int ret;
    ret = fork();
    printf("fork() returned %d\n", ret);
    return 0;
}
