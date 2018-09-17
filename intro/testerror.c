#include "apue.h"
#include <errno.h>

int main (int args, char *argv[])
{
  fprintf (stderr, "EAGAIN: %s\n", strerror (EAGAIN));
  errno = EAGAIN;
  perror (argv[0]);
  exit (0);
}
