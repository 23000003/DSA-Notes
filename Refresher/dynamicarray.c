#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dynamicarray.h"

bool insertDynamicFront(dArray *arr, int val){
	
	if(arr->count == arr->max) dynamicReallocate(arr);
	
	if(arr->count++ != 0){
		memcpy(&arr->arr[1], &arr->arr[0], sizeof(int) * arr->count - 1);	
	}
	
	arr->arr[0] = val;
	
	return true;
	
}

bool insertDynamicRear(dArray *arr, int val){
	
	if(arr->count == arr->max) dynamicReallocate(arr);
	
	arr->arr[arr->count++] = val;
	
	return true;
}

bool insertDynamicInto(dArray *arr, int val, int into){
	
	if(into > arr->count) return false;
	
	if(arr->count == arr->max) dynamicReallocate(arr);
	
	int i;
	for(i = 0; i < arr->count && i != into; i++){}
	
	memmove(&arr->arr[i+1], &arr->arr[i], sizeof(int) * (arr->count - i));
	arr->arr[i] = val;
	arr->count++;
	
	return true;
}

bool insertDynamicSorted(dArray *arr, int val){
	
	if(arr->count == arr->max) dynamicReallocate(arr);
	
	int i = 0;

	if(i != arr->count){
		for(i = 0; i < arr->count && val > arr->arr[i]; i++){}
		memmove(&arr->arr[i+1], &arr->arr[i], sizeof(int) * (arr->count - i));
	}

	arr->arr[i] = val;
	arr->count++;
	
	return true;
}

bool deleteDynamicFront(dArray *arr){
	
	if(arr->count == 0) return false;
	
	if(arr->count != 1){
		memmove(&arr->arr[0], &arr->arr[1], sizeof(int) * (arr->count - 1));
	}
	
	arr->count--;
	
	return true;
}

bool deleteDynamicRear(dArray *arr){
	
	if(arr->count == 0) return false;
	
	arr->count--;
	
	return true;
}

bool deleteDynamicItem(dArray *arr, int item){
	
	if(arr->count == 0) return false;
	
	int i = 0;
	
	if(arr->count != 1){
		for(i = 0; i < arr->count && arr->arr[i] < item; i++){}
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

bool deleteDynamicOccurence(dArray *arr, int item){
	
	if(arr->count == 0) return false;
	
	int i, identify = 0;
	for(i = 0; i < arr->count; i++){
		if(arr->arr[i] == item){
			memmove(&arr->arr[i], &arr->arr[i+1], sizeof(int) * (arr->count - i));
			i--;
			arr->count--;
			identify = 1;
		}
	}
	
	return identify == 1;
	
}

void dynamicReallocate(dArray *arr){
	
	arr->max = arr->max + 5;
	
	arr->arr = realloc(arr->arr, sizeof(arr->max));
	
	printf("\n\nArray Reallocated:");
}

void displayDynamic(dArray arr){
	
	int i;
	printf("\nCount: %d\n", arr.count);
	for(i = 0; i < arr.count; i++){
		printf("%d ", arr.arr[i]);
	}
}




