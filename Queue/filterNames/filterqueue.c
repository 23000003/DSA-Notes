#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filterqueue.h"

//typedef struct {
//    char fname[30];
//    char lname[30];
//} Name;
//
//typedef struct {
//    Name elems[MAX];
//    int front;
//    int rear;
//} NQueue;

void initNQueue(NQueue *nq){
	nq->front = 1;
	nq->rear = 0;
}

bool isEmpty(NQueue nq){
	return nq.front == (nq.rear + 1) % MAX;
}

bool isFull(NQueue nq){
	return nq.front == (nq.rear + 2) % MAX;
}

void displayQueue(NQueue nq){
	
	while(!isEmpty(nq)){
		Name x = front(nq);
		printf("First Name: %s\n", x.fname);
		printf("Last Name: %s\n\n", x.lname);
		dequeue(&nq);
	}
}

Name createName(char fname[], char lname[]){
	Name n;
	strcpy(n.fname, fname);
	strcpy(n.lname, lname);
	
	return n;
}

bool enqueue(NQueue *nq, Name n){
	if(isFull(*nq)) return false;
	
	nq->rear = (nq->rear + 1) % MAX;
	nq->elems[nq->rear] = n;
	
	return true;
}

bool dequeue(NQueue *nq){
	if(isEmpty(*nq)) return false;
	
	nq->front = (nq->front + 1) % MAX;
	return true;
}

Name front(NQueue nq){
	return nq.elems[nq.front];
}

int countQueue(NQueue q){
	int x = 0;
	
	while(!isEmpty(q)){
		x++;
		dequeue(&q);
	}
	
	return x + 1;
}

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString){
	
	int size = countQueue(*nq);
	
	Name *filtered = malloc(sizeof(Name) * size);
	int count = 0;
	
	NQueue temp;
	initNQueue(&temp);
	
	while(!isEmpty(*nq)){
		Name comp = front(*nq);
		dequeue(nq);
		
		if(strcmp(comp.lname, filterString) == 0){
			filtered[count++] = comp;
		}else{
			enqueue(&temp, comp);
		}
	}
	
	while(!isEmpty(temp)){
		enqueue(nq, front(temp));
		dequeue(&temp);
	}
	
	strcpy(filtered[count].lname, " ");
	
	return filtered;
}

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n){
	
	if(isFull(*nq)) return false;
	
	if(isEmpty(*nq)){
		nq->rear = (nq->rear + 1) % MAX;
		nq->elems[nq->rear] = n;
		return true;
	}
	
	NQueue temp;
	initNQueue(&temp);
	int stopper = 0;
	while(!isEmpty(*nq)){
		
		temp.rear = (temp.rear + 1) % MAX;
		
		if(strcmp(nq->elems[nq->front].lname, n.lname) > 0 && stopper == 0){
			temp.elems[temp.rear] = n;
			temp.rear = (temp.rear + 1) % MAX;
			stopper = 1;
		}
		
		temp.elems[temp.rear] = nq->elems[nq->front];
		nq->front = (nq->front + 1) % MAX;
	}
	
	if(stopper == 0){
		temp.rear = (temp.rear + 1) % MAX;
		temp.elems[temp.rear] = n;
	}
	
	while(!isEmpty(temp)){
		nq->rear = (nq->rear + 1) % MAX;
		nq->elems[nq->rear] = temp.elems[temp.front];
		temp.front = (temp.front + 1) % MAX;
	}
	
	return true;
}









