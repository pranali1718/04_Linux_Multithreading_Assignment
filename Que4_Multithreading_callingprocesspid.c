#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>

pthread_t M1;

void* fun(void *arg)
{
	printf("\nnewly created thread in execution\n");
	printf("pthread id : %lu\nCalling Process id : %d\n", pthread_self(), getpid());
	
	return NULL;
}


int main(void)
{
	int k;
	
	k = pthread_create(&M1, NULL, fun, NULL);			//thread creation
	
	if(k)
	{
		printf("not created\n");
	}
	
	else
	{
		printf("thread created\n");
		
	}
	
	pthread_join(M1, NULL);
	
	printf("\nExiting main process\n");
	
	return 0;
}