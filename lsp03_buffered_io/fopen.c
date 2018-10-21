//
// Created by atwlam on 10/6/2018.
//

#include <stdio.h>
#include <fcntl.h>

#define FILE_PATH "./fopen.txt"

int main(int argc, char *argv[]) {

    FILE *stream;
    int fd;

    // stream = fopen(FILE_PATH, "w+");
    fd = open(FILE_PATH, O_RDWR, (mode_t) 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    stream = fdopen(fd, "r");
    if (!stream) {
        perror("fopen");
        return 1;
    }


    int c;

    c = fgetc(stream);
    if (c == EOF) {
        perror("fgetc");
        return 1;
    }else{
        printf("c=%c\n", (char) c);
    }

    char buf[1024];
    if (!fgets(buf, 1024, stream)) {
        perror("fgets");
        return 1;
    } else {
        printf("%s\n", buf);
    }

    if (fclose(stream)) {
        perror("fclose");
        return 1;
    }


}

