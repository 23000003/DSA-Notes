#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[30];
    int age;
    char sex;
} Person;

typedef struct node{
    Person data;
    struct node *link;
} NodeType, *NodePtr, *Stack;


void initStack(Stack *s);
bool isEmpty(Stack s);
void displayStack(Stack s);

bool push(Stack *s, Person p);
bool pop(Stack *s);
Person peek(Stack s);
bool insertSorted1(Stack *s, Person p);
bool insertSorted2(Stack *s, Person p);
void sortStack(Stack *s, bool flag);
Person createPerson(char name[], int age, char sex);
int countStack(Stack s);

int main(){
	
	Stack s;
	initStack(&s);
	
	push(&s, createPerson("D", 69, 'F'));
	push(&s, createPerson("A", 21, 'M'));
	push(&s, createPerson("C", 15, 'M'));
	displayStack(s);
	
	printf("==== InsertSorted 1: ==== \n");
	insertSorted1(&s, createPerson("B", 52, 'F'));
	displayStack(s);
	
	printf("==== Sorted Stack: ==== \n");
	sortStack(&s, 1);
	displayStack(s);
	
	
	return 0;
}



void initStack(Stack *s){
	*s = NULL;
}

bool isEmpty(Stack s){
	return s == NULL;
}

void displayStack(Stack s){

	while(!isEmpty(s)){
		Person p = peek(s);
		printf("Name: %s\n", p.name);
		printf("Age: %d\n", p.age);
		printf("Sex: %c\n\n", p.sex);
		s = s->link;
	}

}

bool push(Stack *s, Person p){
	
	Stack temp = malloc(sizeof(NodeType));
	temp->data = p;
	temp->link = *s;
	*s = temp;
	
	return true;
}

bool pop(Stack *s){
	if(isEmpty(*s)) return false;
	
	Stack del = *s;
	*s = (*s)->link;
	free(del);
	
	return true;
}

Person createPerson(char name[], int age, char sex){
	Person s;
	strcpy(s.name, name);
	s.age = age;
	s.sex = sex;
	
	return s;
}

Person peek(Stack s){
	return s->data;
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p){
	if(isEmpty(*s)){
		push(s, p);
		return true;
	}
	
	Stack temp;
	initStack(&temp);
	int stopper = 0;
	
	while(!isEmpty(*s)){
		Person ss = peek(*s);
		if(strcmp(ss.name, p.name) > 0 && stopper == 0){
			push(&temp, p);
			stopper = 1;
		}
		push(&temp, ss);
		pop(s);
	}
	
	if(stopper == 0){
		push(&temp, p);
	}
	
	while(!isEmpty(temp)){
		push(s, peek(temp));
		pop(&temp);
	}
	
	return true;
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack but without using push, pop, and peek functions.*/
bool insertSorted2(Stack *s, Person p){

	if(isEmpty(*s)){
		Stack tempAssign = malloc(sizeof(NodeType));
		tempAssign->data = (*s)->data;
		tempAssign->link = *s;
		*s = tempAssign;
		return true;
	}
	
	Stack temp;
	initStack(&temp);
	int stopper = 0;
	
	while(*s != NULL){
		Stack tempAssign = malloc(sizeof(NodeType));
		tempAssign->data = (*s)->data;
		if(strcmp((*s)->data.name, p.name) > 0 && stopper == 0){
			Stack found = malloc(sizeof(NodeType));
			found->data = p;
			found->link = temp;
			temp = found;
			stopper = 1;
		}
		
		tempAssign->link = temp;
		temp = tempAssign;
		
		Stack del = malloc(sizeof(NodeType));
		del = *s;
		*s = (*s)->link;
		free(del);
	}
	
	if(stopper == 0){
		Stack tempAssign = malloc(sizeof(NodeType));
		tempAssign->data = (*s)->data;
		tempAssign->link = temp;
		temp = tempAssign;
		
	}
	
	
	while(temp != NULL){
		Stack tempAssign = malloc(sizeof(NodeType));
		tempAssign->data = temp->data;
		
		tempAssign->link = *s;
		*s = tempAssign;
		
		temp = temp->link;
	}
	
	return true;
}

int countStack(Stack s){
	int x = 0;
	Stack temp;
	initStack(&temp);
	
	while(!isEmpty(s)){
		x++;
		push(&temp, peek(s));
		pop(&s);
	}
	
	while(!isEmpty(temp)){
		push(&s, peek(temp));
		pop(&temp);
	}
	
	return x;
}

// HOW THE FUCK DO I SORT A STACK WITH ONLY 1 STACK

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack(Stack *s, bool flag){
	//f = desc t = asc
	// B C A D => stack current value
	if(isEmpty(*s)) return false;
	
	int count = countStack(*s) - 1;
	
	if(count == 0){
		printf("Only 1 value");
		return false;
	}
	
	Stack store; // stores the sorted values;
	initStack(&store);
	
	
	Person comp = peek(*s);
	pop(s);
	
	
	
	int i, j, k = 0; // k => to decrement the count for inner loop;
	
	for(i = 0; i < count; i++){
		int count2 = count - k;
		for(j = 0; j < count2; j++){
			Person p = peek(*s);

			if(strcmp(p.name, comp.name) > 0){
				comp = p;
			}else{
				push(s, p);
			}
			pop(s);
		}
		push(&store, comp);
		comp = peek(*s);
		k++;
	}
	
	while(!isEmpty(store)){
		push(s, peek(store));
		pop(&store);
	}
	
}



