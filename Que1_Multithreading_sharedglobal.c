#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

pthread_t threadid1, threadid2;

int var = 100; 


void* thread_increment(void *args)
{

	var++;
	printf("After Incrementing : %d\n",var);

	return NULL;
}


void* thread_decrement(void *args)
{

	var--;
	printf("After Decrementing  : %d\n", var);

	return NULL;
}

int main(void)
{
	// creating two threads for multithreading
	pthread_create(&threadid1, NULL, thread_increment, NULL);
	pthread_create(&threadid2, NULL, thread_decrement, NULL);

	// joining both the threads with main to execute them
	pthread_join(threadid1, NULL);
	pthread_join(threadid2, NULL);

	printf("Exiting From the Main Thread\n");
	
	return 0;
}