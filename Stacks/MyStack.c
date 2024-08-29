#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"
#define MAX 5


//typedef struct{
//	int elems[MAX];
//	int count;
//}Stack;

void initStack(Stack *s){
	s->count = 0;
}

Stack createStack(){
	Stack newStack;
	initStack(&newStack);
	
	return newStack;
}

bool isEmpty(Stack s){
	
	return s.count == 0;
}

bool isFull(Stack s){
	
	return s.count == MAX;
}

void visualize(Stack s){
	int i;
	printf("MyStack: {");
	for(i = 0; i < s.count; i++){
		if(i == s.count - 1){
			printf("%d}\n", s.elems[i]);
		}else{
			printf("%d, ", s.elems[i]);
		}
	}
}

bool push(Stack *s, int item){
	if(isFull(*s)) return false;
	
	s->elems[s->count++] = item;
	
	return true;	
}

bool pop(Stack *s){
	
	if(isEmpty(*s)) return false;
	
	s->count--;
	
	return true;
}

int peek(Stack s){
	
	return s.elems[s.count - 1];
	
}

bool isFound(Stack s, int item){
	if(isEmpty(s)) return false;
	
	while(!isEmpty(s)){
		if(peek(s) == item){
			return true;
		}
	}
	
	return false;
}

Stack removeEven(Stack *s){;
	
	Stack newEven = createStack();
	Stack temp = createStack();
	
	while(!isEmpty(*s)){
		
		(peek(*s) % 2 == 0) ? push(&newEven, peek(*s)) : push(&temp, peek(*s));
//		if(peek(*s) % 2 == 0){
//			push(&newEven, peek(*s));
//		}else{
//			push(&temp, peek(*s));
//		}
		pop(s);
	}
	
	while(!isEmpty(temp)){
		push(s, peek(temp));
		pop(&temp);
	}
	
	return newEven;
}






