#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t semCount;
int count = 0;

void *incThread(void *data) {
  while (1) {
    sem_wait(&semCount);
    count++;
    printf("IncThread: %d\n", count);
    sem_post(&semCount);
  }
}

void *decThread(void *data) {
  while (1) {
    sem_wait(&semCount);
    count--;
    printf("DecThread: %d\n", count);
    sem_post(&semCount);
  }
}

int main(int argc, char const *argv[]) {
  pthread_t incTid, decTid;

  sem_init(&semCount, 0, 1);
  pthread_create(&incTid, NULL, incThread, NULL);
  pthread_create(&decTid, NULL, decThread, NULL);

  pthread_join(incTid, NULL);
  pthread_join(decTid, NULL);
  sem_destroy(&semCount);

  return 0;
}
