#ifndef STATICARRAY_H
#define STATICARRAY_H
#define MAX 10

typedef struct{
	int count;
	int arr[MAX];
}sArray;

bool insertStaticFront(sArray *arr, int val);
bool insertStaticRear(sArray *arr, int val);
bool insertStaticInto(sArray *arr, int val, int into);
bool insertStaticSorted(sArray *arr, int val);
bool deleteStaticFront(sArray *arr);
bool deleteStaticRear(sArray *arr);
bool deleteStaticItem(sArray *arr, int item);
bool deleteStaticOccurence(sArray *arr, int item);
void displayStatic(sArray arr);

#endif
