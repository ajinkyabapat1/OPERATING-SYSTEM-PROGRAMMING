#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
void *th1(int *data)
{
	printf("\n This is first thread");
	sleep(2);
	printf("\n After waiting in thread1");
}

void *th2(int *data)
{
	printf("\n This is second thread");
	sleep(2);
	printf("\n After waiting in thread2");
}

int main(int argc,char *argv[])
{
	pthread_t thread1,thread2;
	
	pthread_create(&thread1,NULL,th1,NULL);
	pthread_create(&thread2,NULL,th2,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
return 0;
}
