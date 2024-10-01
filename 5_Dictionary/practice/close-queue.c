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

//Functions
Queue ExpiredProducts(Dictionary *dic, Date date, int key);
int compareDate(Date d1, Date d2);
