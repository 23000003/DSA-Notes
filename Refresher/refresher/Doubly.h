#ifndef DOUBLY_H
#define DOUBLY_H

typedef struct node{
	int val;
	struct node *next;
	struct node *prev;
}*Doubly;

void display(Doubly node);
void createNode(Doubly *node, int val);
void insertFront(Doubly *node, int val);
void insertRear(Doubly *node, int val);
void insertInto(Doubly *node, int val, int into);
void insertSorted(Doubly *node, int val);

void deleteFront(Doubly *node);
void deleteRear(Doubly *node);
void deleteItem(Doubly *node, int item);
void deleteLocation(Doubly *node, int location);
void deleteOccurence(Doubly *node);

#endif
