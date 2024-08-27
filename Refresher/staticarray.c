#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
#include "staticarray.h"

bool insertStaticFront(sArray *arr, int val){
	
	if(arr->count == MAX) return false;
	
	if(arr->count == 0){
		arr->arr[arr->count++] = val;
		return true;
	}
	
	arr->count++;
	memmove(&arr->arr[1], &arr->arr[0], sizeof(int) * (arr->count - 1));
	arr->arr[0] = val;
		
	return true;
}

bool insertStaticRear(sArray *arr, int val){
	
	if(arr->count == MAX) return false;
	
	arr->arr[arr->count++] = val;
}

bool insertStaticInto(sArray *arr, int val, int into){
	
	if(arr->count == MAX || into > arr->count) return false;
	
	int i;
	
	for(i = 0; i < arr->count && i != into; i++){}
	
	memmove(&arr->arr[i+1], &arr->arr[i], sizeof(int) * (arr->count - i));
	
	arr->count++;
	arr->arr[i] = val;
	
	return true;
}

bool insertStaticSorted(sArray *arr, int val){
	
	if(arr->count == MAX) return false;
	
	int i = 0;
	
	if(i != arr->count){
		for(i = 0; i < arr->count && val > arr->arr[i]; i++){}
		memmove(&arr->arr[i+1], &arr->arr[i], sizeof(int) * (arr->count - i));
	}
	
	arr->arr[i] = val;
	arr->count++;
	
	return true;
}

bool deleteStaticFront(sArray *arr){
	
	if(arr->count == 0) return false;
	
	if(arr->count != 1){
		memmove(&arr->arr[0], &arr->arr[1], sizeof(int) * (arr->count - 1));
	}
	
	arr->count--;
	
	return true;
}


bool deleteStaticRear(sArray *arr){
	
	if(arr->count == 0) return false;
	
	arr->count--;
	
	return true;
}

bool deleteStaticItem(sArray *arr, int item){
	
	if(arr->count == 0) return false;
	
	int i = 0;
	
	if(arr->count != 1){
		for(i = 0; i < arr->count && item != arr->arr[i]; i++){}
	}
	
	if(arr->arr[i] == item){
		if(arr->count != 1){
			memmove(&arr->arr[i], &arr->arr[i+1], sizeof(int) * (arr->count - i));
		}
		arr->count--;
		return true;
	}
	
	return false;
}

bool deleteStaticOccurence(sArray *arr, int item){
	
	if(arr->count == 0) return false;
	
	int i, identify = 0;


	for( i = 0; i < arr->count; i++){
		if(arr->arr[i] == item){
			identify = 1;
			memmove(&arr->arr[i], &arr->arr[i+1], sizeof(int) * (arr->count - i));
			i--;
			arr->count--;
		}
	}
	
	return identify == 1;
}

void displayStatic(sArray arr){
	
	int i;
	printf("\nCount: %d\n", arr.count);
	for(i = 0; i < arr.count; i++){
		printf("%d ", arr.arr[i]);
	}
}
