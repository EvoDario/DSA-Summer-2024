#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Stack_Array.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	StackArrayList ST = createStack(), even = createStack();
	
	stack_push(&ST, 5);
	stack_push(&ST, 2);
	stack_push(&ST, 1);
	stack_push(&ST, 6);
	
	
	display(ST);
	printf("\n\n");
	even = stackEvens(&ST);

	display(even);
	
	return 0;
}
