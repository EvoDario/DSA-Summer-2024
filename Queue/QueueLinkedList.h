#ifndef QUEUE_LINKEDLIST
#define QUEUE_LINKEDLIST

#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} *nodePtr;

typedef struct{
	nodePtr head;
	nodePtr tail;
}Q;

void initQueue(Q*);
void Enqueue(Q*, int);
int Dequeue(Q*);
bool isEmpty(Q);
void display(nodePtr);

//Others
//Create all function definition

#endif
