#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int a,b;
int sum;
sem_t semT1T2, semT2T1;

void *inputThread(void *data) {
  while (1) {
    sem_wait(&semT2T1);
    printf("Input values for a & b\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("a,b: %d : %d\n", a,b);
    sem_post(&semT1T2);
  }
}

void *calcThread(void *data) {
  while (1) {
    sem_wait(&semT1T2);
    sum=a+b;
    printf("Calc: %d\n", sum);
    sem_post(&semT2T1);
  }
}

int main(int argc, char const *argv[]) {
  pthread_t inputTid, calcTid;

  sem_init(&semT1T2, 0, 0);
  sem_init(&semT2T1, 0, 1);
  pthread_create(&inputTid, NULL, inputThread, NULL);
  pthread_create(&calcTid, NULL, calcThread, NULL);

  pthread_join(inputTid, NULL);
  pthread_join(calcTid, NULL);
  sem_destroy(&semT1T2);
  sem_destroy(&semT2T1);

  return 0;
}
