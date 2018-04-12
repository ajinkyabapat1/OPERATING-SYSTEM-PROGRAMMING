#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *guiThread(void *data) {
  printf("Gui init started\n");
  sleep(5);
  printf("Gui init over\n");
}

void *netThread(void *data) {
  printf("Net init started\n");
  sleep(9);
  printf("Net init over\n");
}

void *logThread(void *data) {
  printf("Log init started\n");
  sleep(7);
  printf("Log init over\n");
}

int main(int argc, char const *argv[]) {
  pthread_t guiTid, decTid, logTid;

  pthread_create(&guiTid, NULL, guiThread, NULL);
  pthread_create(&decTid, NULL, netThread, NULL);
  pthread_create(&logTid, NULL, logThread, NULL);

  pthread_join(guiTid, NULL);
  pthread_join(decTid, NULL);
  pthread_join(logTid, NULL);
  return 0;
}
