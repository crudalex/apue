//
// Created by atwlam on 10/19/18.
//


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define FILE_NAME "./sparse.hole"
#define FILE_SIZE 1024 * 1024 * 1024 * 1024

int main(int argc, char *argv[]) {

    int fd;
    fd = open(FILE_NAME, O_WRONLY | O_CREAT, (mode_t) 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    off_t ret;
    // ret = lseek(fd, (off_t) 1825, SEEK_SET);
    // ret = lseek(fd, 0, SEEK_END);
    // ret = lseek(fd, 0, SEEK_CUR);
    ret = lseek(fd, (off_t) FILE_SIZE - 1, SEEK_CUR);
    if (ret == (off_t) -1) {
        perror("lseek");
        close(fd);
        return 1;
    }

    ssize_t nr;
    nr = write(fd, "", 1);
    if (nr < 0) {
        perror("write");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
    }
    printf("Sparse file created");
}

