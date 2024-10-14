#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr, *BST;

typedef struct{
    struct node *front;
    struct node *rear;
}*Queue, QueCalloc;

void initBST(BST *bst);
BST newBST();// same ^^
bool insertBST(BST *bst, int data);

// DFS
void PostOrder(BST bst);
void PreOrder(BST bst);
void InOrder(BST bst);

// BFS
void BreadOrder(BST bst);

//Queue
Queue initQueue();
bool enqueue(Queue *q, int data);
bool dequeue(Queue *q);

int main(){
    BST bst = newBST();
    
    insertBST(&bst, 9); // Root
    insertBST(&bst, 7); 
    insertBST(&bst, 15);
    insertBST(&bst, 6); 
    insertBST(&bst, 10); 
    insertBST(&bst, 5); 
    insertBST(&bst, 13); 
    insertBST(&bst, 4); 
    
    // 13 10 15 4 5 6 7 9 with recursive
    InOrder(bst); // 15 13 10 9 7 6 5 4
    
}


BST newBST(){
    BST h = NULL;
    return h;
}

bool insertBST(BST *bst, int data){
    // if(*bst == NULL){
    //     NodePtr insert = calloc(1, sizeof(NodeType));
    //     insert->data = data;
    //     // insert->left = NULL;
    //     // insert->right = NULL;
    //     *bst = insert;
    // }else{
    //     if((*bst)->data < data){
    //         insertBST(&(*bst)->right, data);
    //     }else{
    //         insertBST(&(*bst)->left, data);
    //     }
    // }
    
    NodePtr insert = calloc(1, sizeof(NodeType));
    insert->data = data;
    
    while(*bst != NULL){
        if((*bst)->data == data) return false;
        bst = ((*bst)->data < data) ? &(*bst)->right : &(*bst)->left;
    }
    
    *bst = insert;

    return true;
}

void PostOrder(BST bst){
    if(bst != NULL){
        PostOrder(bst->left);
        PostOrder(bst->right);
        printf("%d ", bst->data);
    }    
}

void PreOrder(BST bst){
    if(bst != NULL){
        printf("%d ", bst->data);
        PreOrder(bst->left);
        PreOrder(bst->right);
    }  
}

void InOrder(BST bst){
    if(bst != NULL){
        InOrder(bst->left);
        printf("%d ", bst->data);
        InOrder(bst->right);
    }    
}

Queue initQueue(){
    Queue q = calloc(1, sizeof(QueCalloc));

    return q;
}

bool enqueue(Queue *q, int data){

    
    return true;
}

void BreadOrder(BST bst){
    Queue q = initQueue();
    
    while(bst != NULL){
        
    }
    
}








