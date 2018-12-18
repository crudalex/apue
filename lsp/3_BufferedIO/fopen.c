//
// Created by Alex Lam on 10/6/2018.
//

#include <stdio.h>
#include <fcntl.h>


#if defined(__linux__)
  #define TEMP_FILE "/tmp/file"
#elif defined(_WIN32)
  #define TEMP_FILE "C:\\temp.file"
#endif

void close_file_as_stream(FILE *pFILE);

FILE *open_file_as_stream_from_fd(int fd);
int open_file_as_fd();
char read_char_from_stream(FILE *pFILE);
FILE *open_file_as_stream(void) {

  FILE *stream;

  stream = fopen(TEMP_FILE, "r");

  if (!stream) {
    perror("fopen");
  }

  return stream;

}

int open_file_as_fd() {
  int fd;
  fd = open(TEMP_FILE, O_RDONLY);
  if (fd == -1) {
    perror("open");
  }

  return fd;
}
FILE *open_file_as_stream_from_fd(int fd) {

  FILE *stream;

  stream = fdopen(fd, "r");

  if (!stream) {
    perror("fdopen");
  }

  return stream;

}
void close_file_as_stream(FILE *pFILE) {

  if (fclose(pFILE) != 0) {
    perror("fclose");
  }

}

int main(int argc, char *argv[]) {

  FILE *stream1;

  stream1 = open_file_as_stream();
  close_file_as_stream(stream1);

  int fd;
  FILE *stream2;
  fd = open_file_as_fd();

  stream2 = open_file_as_stream_from_fd(fd);
  close_file_as_stream(stream2);

  FILE *stream3;
  stream3 = open_file_as_stream();

  char c;

  c = read_char_from_stream(stream3);
  printf("%c", c);

}
char read_char_from_stream(FILE *pFILE) {

  int c;

  c = fgetc(pFILE);
  if (c == EOF) {
    return EOF;
  }

  return (char) c;
}
