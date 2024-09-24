#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Singly.h"

void insertSinglyFront(Singly *node, int val){
	
	Singly temp = malloc(sizeof(struct node2));
	temp->val = val;
	temp->next = *node;
	*node = temp;
	
}

void createSinglyNode(Singly* node, int val){
	
	*node = malloc(sizeof(struct node2));
	(*node)->val = val;
	(*node)->next = NULL;
	
	
}

void insertSinglyRear(Singly *node, int val){
	
	Singly temp = malloc(sizeof(struct node2));
	createSinglyNode(&temp, val);
	
	if(*node == NULL){
		*node = temp;
		return;
	}
	
	Singly *trav;
	for(trav = node; *trav != NULL; trav = &(*trav)->next){}
	*trav = temp;
	
}

bool insertSinglyInto(Singly *node, int val, int into){
	
	Singly temp;
	createSinglyNode(&temp, val);
	
	if(*node == NULL && into == 0){
		*node = temp;
		return true;
	}else if(*node == NULL && into > 0){
		return false;
	}
	int i;
	Singly *trav;
	
	for(i = 0, trav = node; *trav != NULL && i != into; i++, trav = &(*trav)->next){}
	temp->next = *trav;
	*trav = temp;
	
	return true;
}

void insertSinglySorted(Singly *node, int val){
	
	Singly temp;
	createSinglyNode(&temp, val);
	
	if(*node == NULL){
		*node = temp;
		return;
	}
	
	int i;
	Singly *trav;
	
	for(i = 0, trav = node; *trav != NULL && (*trav)->val < val; i++, trav = &(*trav)->next){}
	temp->next = *trav;
	*trav = temp;
	
}

bool deleteSinglyFront(Singly *node){
	
	if(*node == NULL) return false;
	
	Singly del = *node;
	
	*node = (*node)->next;
	free(del);
	
	return true;
}

bool deleteSinglyRear(Singly *node){
	
	if(*node == NULL) return false;
	
	Singly *trav;
	
	for(trav = node; (*trav)->next != NULL; trav = &(*trav)->next){}
	Singly del = *trav;
	*trav = NULL;
	free(del);
}

bool deleteSinglyItem(Singly *node, int item){
	
	if(*node == NULL) return false;
	
	Singly *trav;

	for(trav = node; *trav != NULL && (*trav)->val != item; trav = &(*trav)->next){}
	
	if(*trav != NULL){
		Singly del = *trav;
		*trav = (*trav)->next;
		free(del);
		return true;
	}
	
	return false;
}

bool deleteSinglyOccurence(Singly *node, int occu){
	
	if(*node == NULL || ((*node)->val != occu) && (*node)->next == NULL) return false;
	
	int identify = 0;
	Singly *trav = node;
	
	while(*trav != NULL){
		
		if((*trav)->val == occu){
			identify = 1;
			Singly del = *trav;
			*trav = (*trav)->next;
			free(del);
		}else{
			trav = &(*trav)->next;
		}
	}
	
	return identify == 1;
}


void displaySingly(Singly node){

	while(node != NULL){
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}






