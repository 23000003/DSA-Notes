#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 0XA

typedef enum{EMPTY = 0, DELETED = -1}Boolean;

typedef struct{
    int month, day, year;
}Date;

typedef struct{
    int prodID;
    char prodName[30];
    Date expiry;
    Date production;
}Product;

typedef struct{
    Product *prods; // dynamic
    int front;
    int back;
}Queue;

typedef struct {
    Queue *dict; //dynamic
    int count;
    int max;
}Dictionary;

/**
 * Enqueue: Insert Sorted base on Expiry Date
 * Hash: Multiply each bit indexes of prodID and the Union value of the multipled and prodID
 *        ex. prodID = 5, 0101 index 1 * 3 = (3 : 0011) then Union 0101 and 0011 : Union value: 7 (0111) 
 * 
 * To Do Functions:
 * Queue ExpiredProducts(Dictionary, *Date, int key); 
 *      => returns a Random Queue base on key (hash the key) with the products that is expired base on Date 
 *      => Even if key is returning no elements ( just set the count to 0 to determine empty )
 *      => Delete the elements that is expired in the Dictionary
 * 
 */

//Queue
Queue createQueue();
void initQueue(Queue *q);
bool enqueue(Queue *q, Product p);
bool dequeue(Queue *q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void display(Queue q);

//Dictionary
int getHash(int id);
void initDict(Dictionary *dic);
bool insert(Dictionary *dic, Product p);
bool delete(Dictionary *dic, Product p);
bool resizeDict(Dictionary *dic);
void displayDic(Dictionary d);

//Functions
Queue ExpiredProducts(Dictionary *dic, Date date, int key);
int compareDate(Date d1, Date d2);


int main(){

}

Queue createQueue(){
    Queue q;
    initQueue(&q);
    return q;
}

void initQueue(Queue *q){
    q->back = 0;
    q->front = 1;
    q->prods = malloc(sizeof(Product) * MAX);
}

bool enqueue(Queue *q, Product p){
    if(isFull(*q)) return false;

    q->back = (q->back + 1) % MAX;
    q->prods[q->back] = p;

    return true;
}

bool dequeue(Queue *q){
    if(isEmpty(*q)) return false;

    q->front = (q->front + 1) % MAX;

    return true;
}

bool isEmpty(Queue q){
    return q.front == (q.back + 1) % MAX;
}

bool isFull(Queue q){
    return q.front == (q.back + 2) % MAX;
}

void display(Queue q){
    
    printf("Product in the queue: \n");
    while(!isEmpty(q)){
        printf("ID: %d\n",q.prods[q.front].prodID);
        printf("Name: %s\n",q.prods[q.front].prodName);
        printf("Expiry: %d/%d/%d\n",q.prods[q.front].expiry.day, q.prods[q.front].expiry.month, q.prods[q.front].expiry.year);
        printf("Production: %d/%d/%d\n",q.prods[q.front].production.day, q.prods[q.front].production.month, q.prods[q.front].production.year);
    }

    printf("\n");
}

//Dictionary
int getHash(int id){
    int getIndex = 1, temp = id;
    for(int i = 1; temp > 0; temp >>= 1){
        if(temp & 1){
            getIndex *= i;
        }
    }

    getIndex |= id;

    return getIndex % MAX;
}
void initDict(Dictionary *dic){
    dic->count = 0;
    dic->dict = malloc(sizeof(Queue) * MAX);
    dic->max = MAX;

    for(int i = 0; i < MAX; i++){
        initQueue(&(dic->dict[i]));    
    }
}

bool insert(Dictionary *dic, Product p){
    int hash = getHash(p.prodID);

    if(isEmpty(dic->dict[hash])){
        dic->dict[hash].back = (dic->dict[hash].back + 1) % MAX;
        dic->dict[hash].prods[dic->dict[hash].back] = p;
    }else{
        Queue *temp = (&dic->dict[hash]);
        Queue store;
        initQueue(&store);
        int stopper = 0;
        while(temp->front != (temp->back + 1) % MAX){
            store.back = (store.back + 1) % MAX;
            if(temp->prods[temp->front].prodID < p.prodID && stopper == 0){
                store.prods[store.back] = p;
                stopper = 1;
            }else{
                store.prods[store.back] = temp->prods[temp->back];
                temp->front = (temp->front + 1) % MAX;
            }
        }

        if(stopper == 0){
            store.back = (store.back + 1) % MAX;
            store.prods[store.back] = p;
        }

        dic->dict[hash] = store;
    }
}

void displayDic(Dictionary d){
    printf("Dictionary: \n");
    for(int i = 0; i < d.max; i++){
        printf("[%d]: \n");
        if(!isEmpty(d.dict[i])){
            display(d.dict[i]);
        }
    }
}

bool delete(Dictionary *dic, Product p){

}

bool resizeDict(Dictionary *dic){

}

//Functions
Queue ExpiredProducts(Dictionary *dic, Date date, int key){

}

int compareDate(Date d1, Date d2){

}


