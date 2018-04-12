#include <pthread.h>
#include <stdio.h>

void *helloThread(void *data) { printf("Hello from the thread\n"); }

int main(int argc, char const *argv[]) {
  pthread_t helloTid;

  printf("Before thread create\n");
  pthread_create(&helloTid, NULL, helloThread, NULL);
  pthread_join(helloTid, NULL);
  printf("After thread create\n");
  return 0;
}
