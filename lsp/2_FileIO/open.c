#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    int fd;

    // char *filename;
    // filename = "/Users/atwlam/open.log";

    // fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    // fd = creat(filename, 0600);

    // fd = open(filename, O_RDONLY, 0600);
    // if (fd == -1)
    // {
    //     perror(argv[0]);
    // }

    // unsigned long word;
    // ssize_t nr;

    // nr = read(fd, &word, sizeof(word));
    // if (nr == -1) {
    //   perror(argv[0]);
    // }

    // if (nr != 0) {
    //   write(STDOUT_FILENO, &word, nr);
    //   if (nr == -1) {
    //     perror(argv[0]);
    //   }
    // } else {
    //   printf("zero bytes read");

    // }


    // char *buf;
    // size_t len = sizeof(buf);
    // ssize_t ret;

    // unsigned long *word;

    // while (len != 0 && (ret = read(fd, &buf, len)))
    // {

    // if (ret == -1)
    // {
    //     if (errno == EINTR)
    //     {

    //         continue;
    //     }
    //     if (errno == EAGAIN)
    //     {
    //         printf("File busy, try again later. ");
    //         break;
    //     }
    //     perror("read");
    //     break;
    // }

    // len -= ret;
    // buf += ret;

    // }

    // const char *buf = "My ship is solid";
    // size_t count = strlen(buf);
    // ssize_t nr;

    // nr = write(STDOUT_FILENO, buf, strlen(buf));
    // if (nr == -1)
    // {
    //     perror(argv[0]);
    // }
    // else if (nr != count)
    // {
    //     fprintf(stdout, "Partial write");
    // }


    fd = open("/Users/atwlam/hello.txt", O_WRONLY | O_APPEND | O_CREAT, 0600);
    if (fd == -1)
    {
        perror(argv[0]);
    }

    const char *buf = "My ship is solid sdlf\n";
    size_t len = strlen(buf);

    ssize_t ret, nr;

    while (len != 0 && (ret = write(fd, buf, len)) != 0)
    {
        if (ret == -1)
        {
            if (errno == EINTR)
            {
                continue;
            }

            perror("write");
            break;
        }

        len -= ret;
        buf += ret;
    }

    ret = fsync(fd);
    if (ret == -1)
    {
        perror("fsync");
    }



}
