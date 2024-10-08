#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "filterqueue.h"

int main(){
	
	NQueue q;
	initNQueue(&q);
	
	enqueue(&q, createName("Kenny", "A"));
	enqueue(&q, createName("Luke", "B"));
	enqueue(&q, createName("Joe", "D"));
	printf("==== Display ====\n");
	displayQueue(q);
	
	// Name *x = filterNames(&q, "Maratas");
	// printf("==== Display ====\n");
	// displayQueue(q);
	
	// int i;
	// printf("==== Filtered ====\n");
	// for(i = 0; strcmp(x[i].lname, " ") != 0; i++){
	// 	printf("First Name: %s\n", x[i].fname);
	// 	printf("Last Name: %s\n\n", x[i].lname);
	// }
	
	// printf("==== Display ====\n");
	// displayQueue(q);
	
	printf("==== InsertSorted ====\n");
	insertSorted(&q, createName("OK?!", "C"));
	displayQueue(q);
	
	return 0;
}
