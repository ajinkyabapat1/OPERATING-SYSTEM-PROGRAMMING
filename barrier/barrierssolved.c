#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_barrier_t barr;

void *guiThread(void *data) {
  printf("Gui init started\n");
  sleep(5);
  pthread_barrier_wait(&barr);
  printf("Gui init over\n");
}

void *netThread(void *data) {
  printf("Net init started\n");
  sleep(9);
  pthread_barrier_wait(&barr);
  printf("Net init over\n");
}

void *logThread(void *data) {
  printf("Log init started\n");
  sleep(7);
  pthread_barrier_wait(&barr);
  printf("Log init over\n");
}

int main(int argc, char const *argv[]) {
  pthread_t guiTid, decTid, logTid;
  pthread_barrier_init(&barr, NULL, 3);
  pthread_create(&guiTid, NULL, guiThread, NULL);
  pthread_create(&decTid, NULL, netThread, NULL);
  pthread_create(&logTid, NULL, logThread, NULL);

  pthread_join(guiTid, NULL);
  pthread_join(decTid, NULL);
  pthread_join(logTid, NULL);
  pthread_barrier_destroy(&barr);
  return 0;
}
