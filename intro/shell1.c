#include "apue.h"
#include <sys/wait.h>

int main(void) {
    char buf[1000];
    pid_t pid;
    int status;

    printf("%% ");

    while (fgets(buf, 1000, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;

        }

        if ((pid = fork()) < 0) {
            err_sys("fork error");

        }

        // child
        if (pid == 0) {
            execlp(buf, buf, (char *) 0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        // parent
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}
