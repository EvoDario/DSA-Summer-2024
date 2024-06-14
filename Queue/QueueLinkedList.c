#include<stdio.h>
#include<stdlib.h>
#include "QueueLinkedList.h"
#include<stdbool.h>

void initQueue(Q *queue){
	
	queue->head = NULL;
	queue->tail = NULL;
	
}

void Enqueue(Q *queue, int x){
	
	nodePtr temp=malloc(sizeof(nodePtr));
	if(temp==NULL){
		printf("malloc Failed");
	}
	temp->data = x;
	temp->next = NULL;
	
	if(queue->head==NULL){
		queue->head = temp;
		queue->tail = queue->head;
	}else{
		queue->tail->next = temp;
		queue->tail = queue->tail->next;
	}
	
}
int Dequeue(Q *queue){
	
	int x;
	nodePtr temp = queue->head;
	queue->head = queue->head->next;
	x = temp->data;
	free(temp);
	
	return x;
}

void display(nodePtr head){
	
	if(head==NULL){
		printf("Queue is Empty");
	}else{
		for(;head!=NULL;head=head->next){
			printf("%d ->", head->data);
		}
	}
	
	
}
