//
// Created by atwlam on 10/6/2018.
//

#include <stdio.h>
#include <unistd.h>
#include <poll.h>

#define TIMEOUT 5000

int main(int argc, char *argv[]) {

   // char cwd[256];
   // getcwd(cwd, sizeof(cwd));
   // printf("%s\n", cwd);

    struct pollfd fds[2];
    int ret;

    fds[0].fd = STDIN_FILENO;
    fds[0].events = POLLIN;

    fds[1].fd = STDOUT_FILENO;
    fds[1].events = POLLOUT;

    ret = poll(fds, 2, TIMEOUT);
    if (ret == -1) {
        perror("poll");
        return 1;
    }

    if (!ret) {
        printf("%d seconds elapsed.\n", TIMEOUT);
        return 0;
    }

    if (fds[0].revents & POLLIN) {
        printf("stdin is readable\n");
    }

    if (fds[1].revents & POLLOUT) {
        printf("stdout is writable\n");
    }

    return 0;

}
