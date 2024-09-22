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
	push(&s, createPerson("B", 21, 'M'));
	push(&s, createPerson("A", 15, 'M'));
	displayStack(s);
	
	printf("==== InsertSorted 1: ==== \n");
	insertSorted1(&s, createPerson("B", 52, 'F'));
	displayStack(s);

	printf("==== InsertSorted 2: ==== \n");
	insertSorted1(&s, createPerson("H", 52, 'F'));
	displayStack(s);
	
	printf("==== Sorted Stack: ==== \n");
	sortStack(&s, 1); //0 desc, 1 asc
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

	Stack store;
	initStack(&store);

	//holds the value
	Stack hold = malloc(sizeof(struct node));
	hold->data = p;
	hold->link = NULL;

	while(!isEmpty(*s) && strcmp((*s)->data.name, p.name) < 0){
		NodePtr loopTemp = *s;
		*s = (*s)->link;
		loopTemp->link = store;
		store = loopTemp;
	}

	// even if *s is empty this will trigger
	if(!isEmpty(store)){
		hold->link = *s;
		*s = hold;
		return true;
	}

	hold->link = store;
	store = hold;

	while(!isEmpty(store)){
		NodePtr loopTemp = store;
		store = store->link;
		loopTemp->link = *s;
		*s = loopTemp;
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

// HOW THE FUCK DO I SORT A STACK WITH ONLY 1 STACK ( I DID IT !!!!! )
// stack sorting visualization https://www.youtube.com/watch?v=K0XXVSL4wUo

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack(Stack *s, bool flag){

	Stack temp; 
	initStack(&temp);
	
    while (!isEmpty(*s)) {
        Person p = peek(*s);
        pop(s);
		
		// flag condition in the while to avoid infinity loop
        while (!isEmpty(temp) &&
               ((flag && strcmp(p.name, temp->data.name) < 0) ||  // Ascending order
                (!flag && strcmp(p.name,  temp->data.name) > 0))) { // Descending order
            push(s, peek(temp));
            pop(&temp);
        }
        
		//if the inner while loop is done means it doesn't have any greater/lesser element then push it to the temp
        push(&temp, p);
    }
	
	while(!isEmpty(temp)){
		push(s, peek(temp));
		pop(&temp);
	}

}





