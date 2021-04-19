#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define SIZE 64

int main() {
    int _pipe[2];
    int _pid;
    char _buffer[SIZE];

    if (pipe(_pipe) == -1) {
        perror("pipe() Error");
        exit(-1);
    }

    _pid = fork();
    if (_pid == -1) {
        perror("fork() Error");
        exit(-1);
    }

    if (_pid == 0) {
        printf("%d: I'm a child\n", getpid());

        close(_pipe[0]);

        strcpy(_buffer, "Varhegyi Anett R4105E\0");
        write(_pipe[1], _buffer, sizeof(_buffer));

        close(_pipe[1]);
    } else {
        printf("%d: I'm a parent\n", getpid());

        close(_pipe[1]);

        while (read(_pipe[0], _buffer, sizeof(_buffer)) > 0) {
            printf("%s", _buffer);
        }
        printf("\n");

        close(_pipe[0]);
    }
    wait(NULL);
    return 0;
}
