#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <signal.h>

#define SEM_KEY 0x4321

union semun {
    int val; 
    struct semid_ds *buf; 
    unsigned short *array; 
    struct seminfo *__buf; 
};

void sigchld_handler(int sig) {
    int s;
    waitpid(-1, &s, 0);
}

int main() {
    int ret, i, semid;
    struct sigaction sa;
    union semun su;
    struct sembuf ops[1];

    // Initialize signal handler
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = sigchld_handler;
    ret = sigaction(SIGCHLD, &sa, NULL);

    // Create semaphore
    semid = semget(SEM_KEY, 1, IPC_CREAT | 0600);
    if (semid < 0) {
        perror("semget() failed");
        return 1;
    }

    // Initialize semaphore value
    su.val = 0;
    ret = semctl(semid, 0, SETVAL, su);
    if (ret < 0) {
        perror("semctl() failed");
        return 1;
    }

    // Fork child process
    ret = fork();
    if (ret == 0) { // Child process
        char *str = "SUNBEAM\n";
        for (i = 0; str[i] != '\0'; i++) {
            write(1, &str[i], 1);
            //sleep(1);
        }
        ops[0].sem_num = 0;
        ops[0].sem_op = +1; // Release semaphore
        ops[0].sem_flg = 0;
        ret = semop(semid, ops, 1);
        if (ret < 0) {
            perror("semop() failed");
            _exit(1);
        }
    } else { // Parent process
        char *str = "INFOTEC\n";
        ops[0].sem_num = 0;
        ops[0].sem_op = -1; // Acquire semaphore
        ops[0].sem_flg = 0;
        ret = semop(semid, ops, 1);
        if (ret < 0) {
            perror("semop() failed");
            return 1;
        }
        for (i = 0; str[i] != '\0'; i++) {
            write(1, &str[i], 1);
            //sleep(1);
        }
        // Wait for child process
        waitpid(ret, NULL, 0);
        // Remove semaphore
        semctl(semid, 0, IPC_RMID, 0);
    }
    return 0;
}