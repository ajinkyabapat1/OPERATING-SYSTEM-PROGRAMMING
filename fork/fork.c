#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) 
{
  pid_t id;

  printf("Before fork\n");
  id = fork();
  printf("After fork\n");
  if (0 == id) {
    printf("Child\n");
  } else {
    printf("Parent\n");
  }

  return 0;
}
