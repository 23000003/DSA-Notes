#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Doubly.h"

void insertFront(Doubly *node, Doubly *tail, int val){
    
    Doubly temp = malloc(sizeof(struct node));
    temp->next = *node;
    
    if(*node != NULL){
    	(*node)->prev = temp;
	}else{
		*tail = temp;
	}
//    (*node != NULL) ? (*node)->prev = temp : *tail = temp;
    
    temp->prev = NULL;
    temp->val = val;
    *node = temp;
}

void createNode(Doubly *node, int val){
	
	*node = malloc(sizeof(struct node));
	(*node)->next = NULL;
	(*node)->val = val;
	(*node)->prev = NULL;

}

void insertRear(Doubly *node, Doubly *tail, int val){
	
	Doubly temp = NULL;
	createNode(&temp, val);
	
	if(*node == NULL){
		*node = temp;
		*tail = temp;
	}else{
		(*tail)->next = temp;
		temp->prev = *tail;
		*tail = temp;
	}
	
}


void insertInto(Doubly *node, Doubly *tail, int val, int into) {
    
	Doubly temp = NULL;
    createNode(&temp, val);


    // If inserting at the head of the list (into == 0)
    if (into == 0) {
        temp->next = *node;
        if (*node != NULL) {
            (*node)->prev = temp;
        } else {
            // If the list was empty, update the tail pointer
            *tail = temp;
        }
        *node = temp;
        return;
    }

	if (temp == NULL) {
        return;
    }

    Doubly *trav = node;
    int i;
    for (i = 0; i < into - 1 && *trav != NULL; i++, trav = &(*trav)->next) {}

    // If we reached the end of the list before the desired position
    if (*trav == NULL) {
        // Position is out of bounds, free allocated node and return
        free(temp);
        return;
    }

    // Insert temp after *trav
    temp->next = (*trav)->next;
    temp->prev = *trav;

    if ((*trav)->next != NULL) {
        (*trav)->next->prev = temp;
    } else {
        // If inserting at the end of the list, update the tail pointer
        *tail = temp;
    }

    (*trav)->next = temp;
}

void insertSorted(Doubly *node, Doubly *tail, int val){
	
	Doubly temp = NULL;
	createNode(&temp, val);
	
	Doubly *trav;
	int identifier = 0;
	
	for(trav = node, identifier; (*trav)->next != NULL && (*trav)->val < val; trav = &(*trav)->next, identifier++){}
		
		
	if(identifier == 0){
		(*trav)->prev = temp;
		temp->next = *trav;
		*trav = temp;
	}else{
		temp->next = (*trav)->next;
		temp->prev = *trav;
		if((*trav)->next != NULL){
			(*trav)->next->prev = temp;
		}else{
			*tail = temp;
		}
		(*trav)->next = temp; 
	}
	
}

bool deleteFront(Doubly *node, Doubly *tail){ 
	
	if(*node == NULL) return false;
	
	Doubly del = *node;
	*node = (*node)->next;
	
	if(*node == NULL){
		*tail = NULL;
	}else{
		(*node)->prev = NULL;	
	}
	
	free(del);
	
	return true;
}

bool deleteRear(Doubly *tail, Doubly *node){ 
	
	if(*tail == NULL) return false;
	
	Doubly del = *tail;
	*tail = (*tail)->prev;
	
	if(*tail == NULL){
		*node = NULL;
	}else{
		(*tail)->next = NULL;
	}
	
	free(del);

	return true;
}

bool deleteItem(Doubly *node, Doubly *tail, int item){
	
	if(*node == NULL) return false;

	if((*node)->val == item){
		Doubly del = *node;
		*node = (*node)->next;
		(*node)->prev = NULL;
		free(del);
		return true;
	}

	Doubly *trav;
	
	for(trav = node; *trav != NULL && (*trav)->val != item; trav = &(*trav)->next){}
	
	if(*trav == NULL) return false;
	
	Doubly del = *trav;
	
	if((*trav)->next == NULL){
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
	}else{
		(*trav)->next->prev = (*trav)->prev;
		*trav = (*trav)->next;
	}
	
	free(del);
	return true;
}

bool deleteLocation(Doubly *node, Doubly *tail, int location){
	
	if(*node == NULL) return false;

	if(location == 0){
		Doubly del = *node;
		*node = (*node)->next;
		(*node)->prev = NULL;
		free(del);
		return true;
	}

	Doubly *trav;
	int i;
	for(trav = node, i = 0; *trav != NULL && i != location; trav = &(*trav)->next, i++){}
	
	if(*trav == NULL) return false;
	
	Doubly del = *trav;
	
	if((*trav)->next == NULL){
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
	}else{
		(*trav)->next->prev = (*trav)->prev;
		*trav = (*trav)->next;
	}
	
	free(del);
	return true;
	
}

bool deleteOccurence(Doubly *node, Doubly *tail, int occu){
	
	if(*node == NULL || (*node)->next == NULL) return false;

	Doubly *trav = node;
	int identify = 0;
	
	while(*trav != NULL){
		
		if((*trav)->val == occu){
			Doubly del = *trav;
			if((*trav)->next != NULL){
				(*trav)->next->prev = (*trav)->prev;
			}else{
				*tail = (*tail)->prev;
			}
			*trav = (*trav)->next;
			free(del);
			identify = 1;
		}else{
			trav = &(*trav)->next;
		}
		
	}
	
	return identify == 1;
}

void display(Doubly node, Doubly tail){
	
	printf("Front: ");
    while(node != NULL){
        printf("%d ", node->val);
        node = node->next;
	}
	
	printf("\nPrev: ");
	while(tail != NULL){
		printf("%d ", tail->val);
        tail = tail->prev;
	}
	printf("\n");
}
