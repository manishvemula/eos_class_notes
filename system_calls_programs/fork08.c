#include <unistd.h>
#include <stdio.h>

int main() {
    int ret;
    ret = fork();
    if(ret == 0) {
        printf("child: fork() returned: %d\n", ret);
        printf("child: child's pid: %d\n", getpid());
        printf("child: child's parent pid: %d\n", getppid());
    }
    else {
        printf("parent: fork() returned: %d\n", ret);
        printf("parent: parent's pid: %d\n", getpid());
        printf("parent: parent's parent pid: %d\n", getppid());
    }
    sleep(1);
    return 0;
}
