//
// Created by atwlam on 10/6/2018.
//

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    int fd = open("error.txt", O_WRONLY);
    char *str = "hello world";

    write(fd, &str, sizeof(&str));

    if (fsync(fd) == -1) {
        const int err = errno;
        fprintf(stderr, "fsync failed: %s\n", strerror(errno));
        if (err == EIO) {
            fprintf(stderr, "I/O error on %d\n", fd);
            exit(EXIT_FAILURE);
        }

    }

    close(fd);
}
