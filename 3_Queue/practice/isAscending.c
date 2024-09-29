#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 0XA

/**
 * return TRUE if Queue is in ascending order based from ID
 * isAscending(); functions accepts a list and returns TRUE if Asc and FALSE if otherwise
*/

typedef enum{TRUE = 1, FALSE = 0}Boolean;

typedef struct{
    char fName[24];
    char lName[16];
}Name;

typedef struct{
    unsigned int ID;
    Name name;
}Element;

typedef struct node{
    Element stud;
    struct node *link;
}*qptr;

typedef struct{
    qptr front;
    qptr rear;
    int count;
}Queue;

Queue createQueue();
Element front(Queue q);
void initQueue(Queue *q);
void display(Queue q);
bool isEmpty(Queue q);
bool enqueue(Queue *q, Element n);
bool dequeue(Queue *q);

bool isAscending(Queue q);


int main(){

    Queue q = createQueue();

    Element e = {10, "Kenny"};
    enqueue(&q, e);
    Element e1 = {11, "KDWA"};
    enqueue(&q, e1);
    Element e2 = {15, "WADWA"};
    enqueue(&q, e2);

    // dequeue(&q);
    display(q);

    printf("\nIs Ascending?: %s", isAscending(q) ? "TRUE" : "FALSE");
    
    return 0;
}


Queue createQueue(){
    Queue q;
    initQueue(&q);
    return q;
}

void initQueue(Queue *q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue q){
    return q.count == 0;
}

Element front(Queue q){
    return q.front->stud;
}

bool enqueue(Queue *q, Element n){

    qptr store = malloc(sizeof(struct node));
    store->link = NULL;
    store->stud = n;

    if(q->front == NULL){
        q->front = store;
        q->rear = store;
    }else{
        q->rear->link = store;
        q->rear = store; 
    }
    q->count++;

    return TRUE;
}

bool dequeue(Queue *q){
    if(isEmpty(*q)) return FALSE;

    qptr del;
    del = q->front;
    q->front = q->front->link;
    free(del);

    q->count--;

    return TRUE;
}

bool isAscending(Queue q){
    
    Element temp = q.front->stud;
    q.front = q.front->link;
    q.count--;

    while(!isEmpty(q)){
        if(q.front->stud.ID < temp.ID){
            return FALSE;
        }
        temp = q.front->stud;
        q.front = q.front->link;
        q.count--;
    }
    return TRUE;
}

void display(Queue q){
    
    printf("Elements: \n");

    while(!isEmpty(q)){
        Element s = front(q);
        printf("%d\n", s.ID);

        q.front = q.front->link;
        q.count--;
    }

    printf("\n");
}
