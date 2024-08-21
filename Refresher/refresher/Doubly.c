#include <stdio.h>
#include <stdlib.h>
#include "Doubly.h"

void insertFront(Doubly *node, int val){
    
    Doubly temp = malloc(sizeof(struct node));
    temp->next = *node;
    
    if(*node != NULL){
    	(*node)->prev = temp;
	}
    
    temp->prev = NULL;
    temp->val = val;
    *node = temp;
}

void createNode(Doubly *node, int val){
	
	Doubly temp = malloc(sizeof(struct node));
	temp->next = NULL;
	temp->val = val;
	temp->prev = NULL;
	
	*node = temp;
}

void insertRear(Doubly *node, int val){
	
	Doubly temp = NULL;
	createNode(&temp, val);
	
	Doubly *trav = node;
	
	
	if(*trav == NULL){
		*trav = temp;
	}else{
		for(trav; (*trav)->next != NULL; trav = &(*trav)->next){}
		temp->prev = *trav;
		(*trav)->next = temp;	
	}
}

void insertInto(Doubly *node, int val, int into){ // not yet
	
	Doubly temp = NULL;
	createNode(&temp, val);
	
	Doubly *trav = NULL;
	int i;
	
	for(i = 0, trav = node; (*trav)->next != NULL && i < into - 1; trav = &(*trav)->next, i++){}
	temp->next = (*trav)->next;
	temp->prev = *trav;
	(*trav)->next->prev = temp;
	(*trav)->next = temp; 
}

void insertSorted(Doubly *node, int val){
	
}

void deleteFront(Doubly *node){
	
	Doubly del = *node;
	*node = (*node)->next;
	(*node)->prev = NULL;
	free(del);
}

void deleteRear(Doubly *node){
	
	Doubly *trav = NULL;
	
	for(trav = node; (*trav)->next != NULL; trav = &(*trav)->next){}
	
	Doubly del = *trav;
	*trav = NULL;
	free(del);
	
}

void deleteItem(Doubly *node, int item){
	
}

void deleteLocation(Doubly *node, int location){
	
}

void deleteOccurence(Doubly *node){
	
}

void display(Doubly node){
	
	printf("Next: ");
    while(node != NULL){
        printf("%d ", node->val);
        node = node->next;
    	
    	if(node->next == NULL ){
    		
    		printf("%d ", node->val);
    		printf("\nPrevious: ");
    		
    		while(node != NULL){
		    	printf("%d ", node->val);
		    	node = node->prev;
			}
			return;
		}
	}
    
}
