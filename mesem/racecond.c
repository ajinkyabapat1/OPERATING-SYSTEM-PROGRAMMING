#include <pthread.h>
#include <stdio.h>

int count = 0;

void *incThread(void *data) {
  while (1) {
    count++;
    printf("IncThread: %d\n", count);
  }
}

void *decThread(void *data) {
  while (1) {
    count--;
    printf("DecThread: %d\n", count);
  }
}

int main(int argc, char const *argv[]) {
  pthread_t incTid, decTid;

  pthread_create(&incTid, NULL, incThread, NULL);
  pthread_create(&decTid, NULL, decThread, NULL);

  pthread_join(incTid, NULL);
  pthread_join(decTid, NULL);

  return 0;
}
