#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

//assignment: find and return the even in the queue and remove them in the original queue
//practice: apply structures 

typedef struct{
    int elems[MAX];
    int rear, front;
}Queue;


Queue createQueue();
bool enqueue(Queue *q, int val);
bool dequeue(Queue *q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void displayQ(Queue q);
void initQueue(Queue *q);
int front(Queue q);


int main(){
    
    Queue q = createQueue();
    
    enqueue(&q, 5);
    enqueue(&q, 2);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 13);
    displayQ(q);
    
    return 0;
}


void initQueue(Queue *q){
    q->front = 1;
    q->rear = 0;
}

Queue createQueue(){
    Queue myQ;
    initQueue(&myQ);
    
    return myQ;
}

bool isEmpty(Queue q){
    return q.front == (q.rear + 1) % MAX;
}

bool isFull(Queue q){
    return q.front == (q.rear + 2) % MAX;
}


bool enqueue(Queue *q, int val){
    if(!isFull(*q)){
        q->rear = (q->rear + 1) % MAX;
        q->elems[q->rear] = val;
        return true;
    }else{
        printf("Queue is FULL");
        return false;
    }
}

bool dequeue(Queue *q){
    
    if(!isEmpty(*q)){
        q->front = (q->front + 1) % MAX;
        return true;
    }else{
        printf("Queue is Empty");
        return false;
    }
    
}

int front(Queue q){
    return q.elems[q.front];
}

void displayQ(Queue q){
    
    while(!isEmpty(q)){
        printf("%d ", front(q));
        dequeue(&q);
    }
       
}



