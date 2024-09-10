#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "MyData.h"

int main(){
	
	Queue myQ = createQueue();
	(dequeue(&myQ)) ? printf("Success") : printf("Empty");
	(enqueue(&myQ, createData(23000003, createName("Kenny", "Maratas"), "BSIT", 'M'))) ? printf("\n\nSuccess\n\n") : printf("Failed");
	(enqueue(&myQ, createData(32167867, createName("Joe", "Harry"), "BSCE", 'F'))) ? printf("\n\nSuccess\n\n") : printf("Failed");
	visualize(myQ);
//	(dequeue(&myQ)) ? printf("\n\nSuccess\n\n") : printf("Empty");
	(enqueue(&myQ, createData(5436547, createName("WAWA", "Rry"), "BSCS", 'F'))) ? printf("\n\nSuccess\n\n") : printf("Failed");
	(enqueue(&myQ, createData(7542134, createName("LWAO", "way"), "BSIS", 'F'))) ? printf("\n\nSuccess\n\n") : printf("Failed");
	(enqueue(&myQ, createData(6455324, createName("<WADO", "hrwa"), "BSCE", 'F'))) ? printf("\n\nSuccess\n\n") : printf("Failed");
	(enqueue(&myQ, createData(4213435, createName("TWAE", "Hdwad"), "BSCE", 'F'))) ? printf("\n\nSuccess\n\n") : printf("Failed");
	
	visualize(myQ);
	(insertSorted(&myQ, createData(123456, createName("Check", "ZAImmm"), "BSCE", 'F'))) ? visualize(myQ) : printf("Failed");
	
	Name *studs = getStudent(myQ, " ", 'F');
	int i = 0;
	printf("======== GetStudent ==========\n");
	for(i = 0; strcmp(studs[i].fname, " ") != 0; i++){
		printf("Full name: %s %s\n", studs[i].fname, studs[i].lname);
	}
	
	visualize(myQ);

}

void initQueue(Queue *q){
	q->head = NULL;
	q->tail = NULL;
}

Queue createQueue(){
	Queue q;
	initQueue(&q);
	return q;
}

bool isEmpty(Queue q){
	return (q.head && q.tail) == NULL;
}

Name createName(char fname[], char lname[]){
	Name x;
	strcpy(x.fname, fname);
	strcpy(x.lname, lname);
	
	return x;
}

Data createData(int studID, Name studName, char program[], char sex){
	Data x;
	x.studID = studID;
	x.studName = studName;
	strcpy(x.program, program);
	x.sex = sex;
	return x;
}


bool enqueue(Queue *q, Data d){
	NodePtr temp = malloc(sizeof(NodeType));
	
	if(temp == NULL) return false;
	
	temp->link = NULL;
	temp->elem = d;
	
	if(q->head == NULL){
		q->head = temp;
		q->tail = temp;
	}else{
		q->tail->link = temp;
		q->tail = q->tail->link;
	}
	
	return true;
}

bool dequeue(Queue *q){
	if(isEmpty(*q)) return false;
	
	NodePtr del;
	del = q->head;
	q->head = q->head->link;
	free(del);
	 
	return true;
}

Data front(Queue q){
	
}

void display(Queue q){ // dont traverse, 
	
}


void visualize(Queue q){
	
	NodePtr trav = q.head;
	printf("======== Students ==========\n");
	while(trav != NULL){
		printf("Student ID: %d\n", trav->elem.studID);
		printf("Full name: %s %s\n", trav->elem.studName.fname, trav->elem.studName.lname);
		printf("Program: %s\n", trav->elem.program);
		printf("Sex: %c\n\n", trav->elem.sex);
		trav = trav->link;
	}
}

//typedef struct{
//	char fname[20];
//	char lname[20];
//}Name;
//
//typedef struct{
//	int studID;
//	Name studName;
//	char program[8];
//	char sex;
//}Student;

// gets the name of the student that matches with the program and sex,
// If program is an empty string then use all programs, if sexx is an empty character then get both sex
// use the concept of adding an empty string values for the name to use as a terminator for the name array
// create a duplicate queue function

Queue createDuplicateQueue(Queue q){
	Queue myDupli = q;
	return myDupli;
}


Name *getStudent(Queue q, char *program, char sex){
	
	Queue myDupli = q; // save the queue
	Name *studs = malloc(sizeof(Name) * 20);
	int i = 0;
	
	if(strcmp(program, " ") == 0){
		while(myDupli.head != NULL){
			if(myDupli.head->elem.sex == sex){
				studs[i] = myDupli.head->elem.studName;	
				i++;
			}
			dequeue(&myDupli);
		}
	}else if(sex == ' '){
		while(myDupli.head != NULL){
			if(strcmp(myDupli.head->elem.program, program) == 0){
				studs[i] = myDupli.head->elem.studName;	
				i++;
			}
			dequeue(&myDupli);
		}
	}else{
		while(myDupli.head != NULL){
			if(strcmp(myDupli.head->elem.program, program) == 0 && myDupli.head->elem.sex == sex){
				studs[i] = myDupli.head->elem.studName;	
				i++;
			}
			dequeue(&myDupli);
		}
	}

	strcpy(studs[i].fname, " ");
	studs = realloc(studs, sizeof(Name) * i + 1);
	
	return studs;
}

// insert the Data d based on lastname only 
bool insertSorted(Queue *q, Data d){
	
	Queue temp = createQueue();
	int compareStopper = 0;
	//compare stopper to stop the inserting when condition is true;
	while(q->head != NULL){
		if(strcmp(q->head->elem.studName.lname, d.studName.lname) > 0 && compareStopper == 0){
			enqueue(&temp, d);
			compareStopper = 1;	
		}else{
			enqueue(&temp, q->head->elem);
		}
		dequeue(q);
	}
	
	while(temp.head != NULL){
		enqueue(q, temp.head->elem);
		dequeue(&temp);
	}
	
	return true;
}
