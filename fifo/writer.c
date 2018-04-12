#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

  int fd;
  unsigned char buff[128];

  fd = open("dacfifo", O_WRONLY);
  write(fd, "msgwriter\n", 10);
  close(fd);
  return 0;
}
