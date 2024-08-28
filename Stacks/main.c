#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"

int main(){
	
	Stack s = createStack();
	
	push(&s, 5);
	visualize(s);
	push(&s, 3);
	visualize(s);
	push(&s, 8);
	visualize(s);
	
	Stack newStack = removeEven(&s);
	visualize(newStack);
	visualize(s);
//	void initStack(Stack *s);
//	Stack createStack();
//	bool isEmpty(Stack s);
//	bool isFull(Stack s);
//	void visualize(Stack s);
//	
//	bool push(Stack *s, int item);
//	bool pop(Stack *s);
//	int peek(Stack s);
//	
//	bool isFound(Stack s, int item);
//	Stack removeEven(Stack *s);
	return 0;
}
