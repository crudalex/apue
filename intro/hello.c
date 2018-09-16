#include "apue.h"

int
main(void)
{
    printf("hello world from process ID %d, %d, %d\n", (int) getpid(), (int) getppid(), (int) getpgrp());
    exit(0);
}
