#include <stdio.h>
#include <stdlib.h>
#include "Doubly.h"


int main(){
	
	Doubly node = NULL;
	Doubly tail = NULL; 
	insertFront(&node, 5);
	insertRear(&node, 123);
	insertFront(&node, 2);
	insertFront(&node, 3);
	insertRear(&node, 10);

	display(node);
	printf("\n");
	insertInto(&node, 5555, 2);
	display(node);
	
	printf("\n\nDelete: \n");
	deleteFront(&node);
	deleteRear(&node);
	display(node);
	
	return 0;
}
