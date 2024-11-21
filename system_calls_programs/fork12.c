#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("hi, desd!");
    fork();
    printf("bye, desd!\n");
    return 0;
}
