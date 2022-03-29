#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>


void* fun(void *param)
{
	printf("pthread creation using user attributes\n");
	sleep(3);
	return NULL;
}

int main(void)
{
	pthread_attr_t attr;
	pthread_t t1;
	
	void *stck;
	size_t s;
	int err;
	
	size_t size = 5000;
	void * stack;
	
	pthread_attr_init(&attr);			//init attribute
	pthread_attr_getstacksize(&attr, &s);	//get size of stack
	pthread_attr_getstackaddr(&attr, &stck);	//get stack address
	
	printf("default address of stack : %08x default size of stack : %d\n", stck, s);
	
	stack = (void*)malloc(size);		//define a new stack with attributes of our choice
	
	pthread_attr_setstack(&attr, stack, size);			//set stack
	
	pthread_create(&t1, &attr, fun, NULL);
	
	
	pthread_attr_getstack(&attr, &stck, &s);			//get info of new stack
	
	printf("\ndefault address of stack : %08x default size of stack : %d\n", stck, s);
	
	return 0;
}