#include <stdio.h>  //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main()
{
	t_queue *qu;

	qu = queueInit();
	enqueue(qu, "1");
	enqueue(qu, "2");
	enqueue(qu, "3");

	dequeue(qu);
	printf("checking enqueue last:%s\n", qu->last->message);
	printf("checking enqueue first:%s\n", qu->first->message);
	printf("checking peek:%s\n", peek(qu));

	printf("checking deque:%s\n", dequeue(qu));
	printf("checking peek:%s\n", peek(qu));

	printf("checking is empty:%d\n", isEmpty(qu));
	//	printf("checking enqueue first:%s\n", qu->first->message);
	return (0);
}

// Function used for the test
// Don't go further :)
