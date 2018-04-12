#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int fd;
  unsigned char buff[128];

  fd = open("dacfifo", O_RDONLY);
  read(fd, buff, 128);
  printf("Read: %s\n", buff);
  return 0;
}
