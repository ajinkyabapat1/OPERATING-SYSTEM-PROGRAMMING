#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  printf("Process ID: %d\n", getpid());
  printf("Parennt Process ID: %d\n", getppid());
  return 0;
}
