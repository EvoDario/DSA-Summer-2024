#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 6

typedef struct{
	
	int data[MAX+1];
	int front;
	int rear;
}circularQ;

void initCQ(circularQ *Q);
void DQ(circularQ *Q);
void EQ(circularQ *Q, int x);
void display(circularQ Q);
bool isFull(circularQ Q);
bool isEmpty(circularQ Q);

int main(){
	
	circularQ arrQ;
	
	initCQ(&arrQ);
	
	
	EQ(&arrQ, 1);
	EQ(&arrQ, 1);
	EQ(&arrQ, 2);
	EQ(&arrQ, 1);
	EQ(&arrQ, 3);
	EQ(&arrQ, 1);
	
	DQ(&arrQ);
	DQ(&arrQ);
	
	EQ(&arrQ, 7);
	EQ(&arrQ, 7);
	
	DQ(&arrQ);
	DQ(&arrQ);
	
	EQ(&arrQ, 25);
	
	DQ(&arrQ);
	
	EQ(&arrQ, 21);
	EQ(&arrQ, 0);
	
	DQ(&arrQ);
	DQ(&arrQ);
	DQ(&arrQ);
	
	
	display(arrQ);
	
	return 0;
}

bool isEmpty(circularQ Q){
	
	if(((Q.rear+1)%(MAX+1))==Q.front){
		return true;
	}else{
		return false;
	}
	
}

bool isFull(circularQ Q){
	
	if(((Q.rear+2)%(MAX+1))==Q.front){
		return true;
	}else{
		return false;
	}
	
}

void initCQ(circularQ *Q){
	
	Q->front = 0;
	Q->rear = MAX;
	Q->data[0] = NULL;
}

void EQ(circularQ *Q, int x){
	
	if(isFull(*Q)){
		printf("Queue is FULL!");
	}else{
		Q->rear = ((Q->rear+1)%(MAX+1));
		Q->data[Q->rear] = x;
	}
	
}

void DQ(circularQ *Q){
	
	if(isEmpty(*Q)){
		printf("Queue is Empty");
	}else{
		Q->front = (Q->front+1)%(MAX+1);
	}
	
	if(Q->front == Q->rear){
		Q->front = (Q->front+1) % (MAX+1);
	}
	
}

void display(circularQ Q){
	
	int i;
	
	if(isEmpty(Q)){
		printf("Queue is Empty");
	}else{
		printf("Queued = [");
		for(i = Q.front; i!=(Q.rear+1)%(MAX+1); i = (i+1)%(MAX+1)){
			printf("%d ", Q.data[i]);
		}
		printf("]");
	}
	
	
}

