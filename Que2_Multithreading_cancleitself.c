#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_t threadid1, threadid2;

void* thread(void *args)
{

	printf("Now Current  created thread is executing\n");

	for(int p=0; p<9; p++)
		printf("p: %d\n",p);

	while(1);

	return NULL;
}

int main(void)
{
	int q=0;
	int abc=pthread_create(&threadid1, NULL, thread, NULL);

	if(abc)
		printf("Thread is not Created\n");
	else
		printf("The Thread is created\n");
	
	sleep(6);

	q=pthread_cancel(threadid1);

	if(q == 0)
		printf("Now The Thread is Cancled\n");

	printf("Now Exiting From The Main Thread\n");
	
	return 0;
}