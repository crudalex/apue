//
// Created by atwlam on 10/19/18.
//

#include <fcntl.h>
#include <stdio.h>
#include <zconf.h>
#include <memory.h>

#define FILE_NAME "/home/atwlam/pirate.txt"

int main(int argc, char *argv[]) {

    int fd;
    fd = open(FILE_NAME, O_WRONLY | O_CREAT, (mode_t) 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    ssize_t ret;
    const char *buf1 = "Edward Teach was a notorious English pirate.\n";
    const char *buf2 = "He was nicknamed blackbeard.\n";
    ret = write(fd, buf1, strlen(buf1));
    ret = write(fd, buf2, strlen(buf1));

    if (close(fd) == -1) {
        perror("close");
    }
}
