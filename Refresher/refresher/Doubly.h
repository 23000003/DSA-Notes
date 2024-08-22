#ifndef DOUBLY_H
#define DOUBLY_H

typedef struct node{
	int val;
	struct node *next;
	struct node *prev;
}*Doubly;

void display(Doubly node, Doubly tail);
void createNode(Doubly *node, int val);
void insertFront(Doubly *node, Doubly *tail, int val);
void insertRear(Doubly *node, Doubly *tail, int val);
void insertInto(Doubly *node, Doubly *tail, int val, int into);
void insertSorted(Doubly *node, Doubly *tail, int val);

bool deleteFront(Doubly *node);
bool deleteRear(Doubly *tail);
bool deleteItem(Doubly *node, Doubly *tail, int item);
bool deleteLocation(Doubly *node, Doubly *tail, int location);
bool deleteOccurence(Doubly *node, Doubly *tail, int occu);

#endif
