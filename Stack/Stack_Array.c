#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Stack_Array.h"


void initStack(StackArrayList *S){
	S->top = -1;
}


StackArrayList createStack(){
	StackArrayList S;
	
	S.top = -1;
	
	return S;
}

bool stack_push(StackArrayList *s, int elem){
	
	if(s->top<MAX){
	s->top++;
	s->data[s->top]= elem;
	return true;
	}else{
	return false;
	}
	

}

bool stack_pop(StackArrayList *s){
	s->top --;
}
int stack_peek(StackArrayList s){
	return s.data[s.top];
}

void display(StackArrayList s){
	
	int i;
	
	if(s.top<0){
		printf("Stack is Empty");
	}else {
	
	for(i=0;i!=s.top+1;i++){
		printf("%d | ", s.data[i]);
	}
	
	}

}

void visualize(StackArrayList s){
	
	printf("index \tvalue \t");
	
	int i;
	
	if(s.top<0){
		printf("Stack is Empty");
	}else {
	
	for(i=0;i!=s.top+1;i++){
		printf("\n%d \t%d \t", i ,s.data[i]);
	}
	printf("TOP");
	
	}

}

StackArrayList stackEvens(StackArrayList *s){
	
	StackArrayList Evens =createStack(), temp= createStack();
	
	for(;(s->top)>=0;stack_pop(s)){	
		
		stack_push(&temp, stack_peek(*s));
		
	}
	
	for(;(temp.top)>=0;stack_pop(&temp)){	
		
		if(stack_peek(temp)%2==0){
			stack_push(&Evens, stack_peek(temp));
		}else{
			stack_push(s,stack_peek(temp));
		}
		
	}

	return Evens;
	
}
