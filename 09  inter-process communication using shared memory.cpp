#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {
    int shmid = shmget(5678, SHM_SIZE, IPC_CREAT | 0666);
    char *shm = shmat(shmid, NULL, 0);
    char *s = shm;

    for (char c = 'a'; c <= 'z'; c++) *s++ = c;
    *s = '\0';

    printf("%s\n", shm);

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}

