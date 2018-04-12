#include <stdio.h>
#include <unistd.h>

#define MAX_BUFFER 128

int main(int argc, char const *argv[]) {
  pid_t id;
  int fd[2];
  unsigned char buff[MAX_BUFFER];

  pipe(fd);
  id = fork();
  if (0 == id) 
  {
    printf("Child\n");
    close(fd[1]);
    read(fd[0], buff, MAX_BUFFER);
    printf("Parent send us %s\n", buff);
    close(fd[0]);
  } else {
    printf("Parent\n");
    close(fd[0]);
    write(fd[1], "Hello\n", 6);
    close(fd[1]);
  }

  return 0;
}
