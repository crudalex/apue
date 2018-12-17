//
// Created by atwlam on 10/19/18.
//

#include <fcntl.h>
#include <stdio.h>
#include <zconf.h>
#include <memory.h>

#define FILE_NAME "/home/atwlam/pirate.txt"

int main(int argc, char *argv[]) {
    int ret;

    ret = truncate(FILE_NAME, 50);
    if (ret == -1) {
        perror("truncate");
        return -1;

    }

    return 0;

}
