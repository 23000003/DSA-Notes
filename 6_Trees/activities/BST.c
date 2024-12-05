#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr, *BST;

typedef struct nodeQ{
    BST data;
    struct nodeQ *next;
}*NodeQPtr;

typedef struct{
    NodeQPtr front;
    NodeQPtr rear;
}Queue;

void initBST(BST *bst);
BST newBST();// same ^^
bool insertBST(BST *bst, int data);
bool deleteBST(BST *bst, int data);

// DFS
void PostOrder(BST bst);
void PreOrder(BST bst);
void InOrder(BST bst);

// BFS
void BreadOrder(BST bst);

//Queue
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

    printf("\n");
    BreadOrder(bst);
    
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

bool deleteBST(BST *bst, int data){
    
    

struct Node* delete(struct Node* node, int value) {
    // Implement me!
    
    if(node == NULL) return node;
    
    struct Node **temp = &node;
    
    for(; *temp != NULL && (*temp)->value != value; temp = ((*temp)->value > value) ? &(*temp)->left : &(*temp)->right){}
    
    if(*temp != NULL){
        
        struct Node *toDel = NULL;
        
        if((*temp)->left != NULL && (*temp)->right != NULL)
        {
            
            struct Node **findRSmall = &(*temp)->right;
            
            while((*findRSmall)->left != NULL){ findRSmall = &(*findRSmall)->left; }
            
            (*temp)->value = (*findRSmall)->value;
            *findRSmall = (*findRSmall)->right;
        }
        else
        {
            struct Node* tempNode = *temp;
            *temp = (*temp)->left != NULL ? (*temp)->left : (*temp)->right;
            free(tempNode);                     
        }
    }
    
    
    return node;
    
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

bool enqueue(Queue *q, int data){

    
    return true;
}

void BreadOrder(BST bst){
    Queue q;

    q.front = NULL;
    q.rear = NULL;

    NodeQPtr nq = malloc(sizeof(struct nodeQ));
    nq->data = bst;
    nq->next = NULL;

    q.front = nq;
    q.rear = nq;
    
    while(q.front != NULL){
        printf("%d ", q.front->data->data);
        if(q.front->data->left != NULL){
            nq = calloc(1, sizeof(struct nodeQ));
            nq->data = q.front->data->left;
            q.rear->next = nq;
            q.rear = nq;
        }
        if(q.front->data->right != NULL){
            nq = calloc(1, sizeof(struct nodeQ));
            nq->data = q.front->data->right;
            q.rear->next = nq;
            q.rear = nq;
        }
        NodeQPtr del = q.front;
        q.front = q.front->next;
        free(del);
    }
}








