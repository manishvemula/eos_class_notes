#include <stdio.h>
#include <unistd.h>

// single threaded process -- main thread.
int main() {
    int i;
    for(i=1; i<=10; i++) {
        printf("main: %d => pid=%d, tid=%d\n", i, getpid(), gettid());
        sleep(1);
    }
    return 0;
}
