#define _GNU_SOURCE

#include <pthread.h>
#include <stdio.h>

pthread_mutex_t countMutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
int count = 0;

void *incThread(void *data) {
  while (1) {
    pthread_mutex_lock(&countMutex);
    printf("IncThread: Grab #1\n");
    pthread_mutex_lock(&countMutex);
    printf("IncThread: Grab #2\n");
    count++;
    printf("IncThread: %d\n", count);
    pthread_mutex_unlock(&countMutex);
    pthread_mutex_unlock(&countMutex);
  }
}

void *decThread(void *data) {
  while (1) {
    pthread_mutex_lock(&countMutex);
    count--;
    printf("DecThread: %d\n", count);
    pthread_mutex_unlock(&countMutex);
  }
}

int main(int argc, char const *argv[]) {
  pthread_t incTid, decTid;

  // pthread_mutex_init(&countMutex, NULL);
  pthread_create(&incTid, NULL, incThread, NULL);
  pthread_create(&decTid, NULL, decThread, NULL);

  pthread_join(incTid, NULL);
  pthread_join(decTid, NULL);
  pthread_mutex_destroy(&countMutex);
  return 0;
}
