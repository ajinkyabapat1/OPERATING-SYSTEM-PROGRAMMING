#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int fd1, fd2;
  unsigned char buff[128];
  unsigned char buffw[128] = "hello\n";

  fd1 = open("/tmp/dac1.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP);
  fd2 = open("/tmp/dac2.txt", O_CREAT | O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP);
  if (-1 == fd1) {
    perror("Error: \n");
    exit(EXIT_FAILURE);
  } else {
    printf("FD: %d\n", fd1);
    printf("FD: %d\n", fd2);
    write(fd1, buffw, 6);
    read(fd2, buff, 128);
    printf("Read : %s\n", buff);
    close(fd1);
    close(fd2);
  }
  return 0;
}
