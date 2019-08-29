#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "apue.h"

void slowShow(const char* str);

int main() {
    // pipefd[0] refers to the read end of the pipe.
    // pipefd[1] refers to the write end of the pipe.
    // Data written to the write end of the pipe is buffered by the 
    // kernel until it is read from the read end of the pipe.
    int pipefd[2];
    if (pipe(pipefd) < 0) {
        err_sys("pipe error");
    }
    pid_t pid;
    if ((pid = fork()) < 0) {
    } else if (pid == 0) {
        // child process
        slowShow("I am child\n");
        exit(0);
    }
    // parent prcess
    slowShow("I am parent\n");
    return 0;
}

void slowShow(const char* str) {
    if (!str) return;
    setbuf(stdout, NULL);
    for (const char *p = str; *p != 0; ++p) {
        putc(*p, stdout);
    }
}
