#ifndef SINGLY_H
#define SINGLY_H

typedef struct node2{
	int val;
	struct node *next;
}*Singly;

void insertSinglyFront(Singly *node, int val);
void insertSinglyRear(Singly *node, int val);
void insertSinglySorted(Singly *node, int val);
bool insertSinglyInto(Singly *node, int val, int into);
void createSinglyNode(Singly* node, int val);
void displaySingly(Singly node);

bool deleteSinglyFront(Singly *node);
bool deleteSinglyRear(Singly *node);
bool deleteSinglyItem(Singly *node, int item);
bool deleteSinglyOccurence(Singly *node, int occu);

#endif


