#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
	int *arr;
	int max;
	int count;
}dArray;


bool insertDynamicFront(dArray *arr, int val);
bool insertDynamicRear(dArray *arr, int val);
bool insertDynamicInto(dArray *arr, int val, int into);
bool insertDynamicSorted(dArray *arr, int val);
bool deleteDynamicFront(dArray *arr);
bool deleteDynamicRear(dArray *arr);
bool deleteDynamicItem(dArray *arr, int item);
bool deleteDynamicOccurence(dArray *arr, int item);
void dynamicReallocate(dArray *arr);
void displayDynamic(dArray arr);

#endif
