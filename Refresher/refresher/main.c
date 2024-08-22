#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Doubly.h"
#include "Singly.h"
#include "staticarray.h"
#include "dynamicarray.h"

int main(){
	
//	=============== DOUBLY LINKEDLIST ==========================
//	
//	Doubly node = NULL;
//	Doubly tail = NULL; 
//	insertFront(&node, &tail, 5);
//	insertFront(&node, &tail, 1);
//	insertRear(&node, &tail, 10);
//	display(node, tail);
//	insertInto(&node,&tail, 5555, 2);
//	display(node, tail);
//	insertSorted(&node, 4);
//	display(node);
	
//	printf("\n\nDelete: \n");
//	(deleteFront(&node)) ? display(node) : printf("Empty LL");
//	(deleteRear(&node)) ? display(node) : printf("Empty LL");
	
	
// ===================== SINGLY LINKED LIST ======================

	Singly node = NULL;

	insertSinglyFront(&node, 5);
	insertSinglyFront(&node, 2);
	insertSinglyFront(&node, 7);
	insertSinglyFront(&node, 5);
	insertSinglyFront(&node, 5);
	insertSinglyFront(&node, 5);
	insertSinglyRear(&node, 50);
	displaySingly(node);
	(insertSinglyInto(&node, 20, 2)) ? displaySingly(node) : printf("\nInsert Into Exceeds");
	insertSinglySorted(&node, 70);
	displaySingly(node);
	
	printf("\n\nDelete:\n");
	(deleteSinglyFront(&node)) ? displaySingly(node) : printf("\nList is empty\n");
	(deleteSinglyRear(&node)) ? displaySingly(node) : printf("\nList is empty\n");
	(deleteSinglyItem(&node, 50)) ? displaySingly(node) : printf("\nItem doesnt exist or List is Empty");
	(deleteSinglyOccurence(&node, 5)) ? displaySingly(node) : printf("\nList is empty");
	
// ================ Static Array ============= //

//	sArray arr;
//	arr.count = 0;
//	
//	(insertStaticFront(&arr, 5)) ? displayStatic(arr) : printf("\n\nArray is Full\n\n");
//	(insertStaticFront(&arr, 3)) ? displayStatic(arr) : printf("\n\nArray is Full\n\n");
//	(insertStaticFront(&arr, 2)) ? displayStatic(arr) : printf("\n\nArray is Full\n\n");
//	(insertStaticRear(&arr, 22)) ? displayStatic(arr) : printf("\n\nArray is Full\n\n");
//	(insertStaticInto(&arr, 100, 3)) ? displayStatic(arr) : printf("\n\nArray is Full or INto Exceeds\n\n");
//	(insertStaticSorted(&arr, 4)) ? displayStatic(arr) : printf("\n\nArray is Full\n\n");
//	(insertStaticSorted(&arr, 4)) ? displayStatic(arr) : printf("\n\nArray is Full\n\n");
//	
//	printf("\n\nDelete:\n");
//
//	(deleteStaticFront(&arr)) ? displayStatic(arr) : printf("Array is Empty");
//	(deleteStaticItem(&arr, 3)) ? displayStatic(arr) : printf("Array is Empty or Item Not Found");
//	(deleteStaticOccurence(&arr, 4)) ? displayStatic(arr) : printf("\n\nArray is Empty or Item Not Found\n\n");
//	(deleteStaticRear(&arr)) ? displayStatic(arr) : printf("Array is Empty");



// ==================== Dynamic Array ================= //

//	dArray arr;
//	arr.count = 0;
//	arr.max = 3;
//	arr.arr = malloc(sizeof(int) * arr.max);
//	
//	(insertDynamicFront(&arr, 5)) ? displayDynamic(arr) : printf("\n\nArray is Full\n\n");
//	(insertDynamicFront(&arr, 2)) ? displayDynamic(arr) : printf("\n\nArray is Full\n\n");
//	(insertDynamicRear(&arr, 12)) ? displayDynamic(arr) : printf("\n\nArray is Full\n\n");
//	(insertDynamicFront(&arr, 2)) ? displayDynamic(arr) : printf("\n\nArray is Full\n\n");
//	(insertDynamicFront(&arr, 2)) ? displayDynamic(arr) : printf("\n\nArray is Full\n\n");
//	(insertDynamicInto(&arr, 400, 4)) ? displayDynamic(arr) : printf("\n\nInto Exceeds\n\n");
//	(insertDynamicSorted(&arr, 3)) ? displayDynamic(arr) : printf("\n\nArray is Full\n\n");
//	
//	printf("\n\nDelete:\n");
//	(deleteDynamicFront(&arr)) ? displayDynamic(arr) : printf("\n\nArray is Empty\n\n");
//	(deleteDynamicRear(&arr)) ? displayDynamic(arr) : printf("\n\nArray is Empty\n\n");
//	(deleteDynamicItem(&arr, 3)) ? displayDynamic(arr) : printf("\n\nArray is Empty or Item Not Found\n\n");
//	(deleteDynamicOccurence(&arr, 2)) ? displayDynamic(arr) : printf("\n\nArray is Empty or Item Not Found\n\n");
	
	
	return 0;
}
