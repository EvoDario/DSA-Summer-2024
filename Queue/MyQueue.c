#include<stdio.h>
#include<stdlib.h>
#include "QueueLinkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Q myQ;
	
	initQueue(&myQ);
	Enqueue(&myQ, 2);
	Enqueue(&myQ, 9);
	Enqueue(&myQ, 1);
	display(myQ.head);
	
	Dequeue(&myQ);
	display(myQ.head);
	
	Enqueue(&myQ, 1);
	Enqueue(&myQ, 2);
	display(myQ.head);
	
	return 0;
}
