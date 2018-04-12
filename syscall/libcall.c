#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  write(1, "Hello ", 6);
  write(1, "World\n", 6);
  return 0;
}
