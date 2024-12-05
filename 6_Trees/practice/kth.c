#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *left, *right;
    int value;
}*BST;

void insertBST(BST *b, int value);
void deleteBST(BST *b, int value);
void findKthElem(BST b, int value);
void InOrder(BST b, int *smallest, int *index, int kth);

int main(){
    
    BST b = NULL;
    
    printf("Enter operations:\n");
    
    char inp;    
    int val;
    while(1){
        scanf(" %c", &inp);  // Add space before %c to handle newlines
        scanf("%d", &val);
        if(inp == '+'){
            insertBST(&b, val);
        }
        else if(inp == '-'){
            deleteBST(&b, val);
        }
        else if(inp == 'O'){
            findKthElem(b, val);
        }else{
            break;
        }
    }
    
    return 0;
}

void insertBST(BST *b, int value){
    
    BST temp = malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->value = value;
    
    if(*b == NULL){
        *b = temp;
        return;
    }
    
    BST *trav = b;
    
    while(*trav != NULL){
        
        if((*trav)->value == value) return;
        
        trav = (*trav)->value > value ? &(*trav)->left : &(*trav)->right;
    }
    
    *trav = temp;
}

void deleteBST(BST *b, int value){
    
    if(*b == NULL) return;
    
    BST *trav = b;
    
    for(; *trav != NULL && (*trav)->value != value; trav = (*trav)->value > value ? &(*trav)->left : &(*trav)->right){}
    
    if(*trav != NULL){
        
        if((*trav)->left != NULL && (*trav)->right != NULL){
            
            BST *findRSmall = &(*trav)->right;
            
            while((*findRSmall)->left != NULL){
                findRSmall = &(*findRSmall)->left;
            }
            
            (*trav)->value = (*findRSmall)->value;
            *findRSmall = (*findRSmall)->right;
        }
        else
        {
            *trav = (*trav)->left != NULL ? (*trav)->left : (*trav)->right;    
        }
    }
}

void findKthElem(BST b, int value){
    if (b == NULL){
        printf("Element not found\n");
        return;
    }
    
    int smallest = 0;
    int index = 0;
    
    InOrder(b, &smallest, &index, value);
    
    if (smallest != 0){
        printf("K-th smallest element (%d): %d\n", value, smallest);  // Print the value
    } else {
        printf("Element not found\n");
    }
}

void InOrder(BST b, int *smallest, int *index, int kth) {
    if (b != NULL){
         InOrder(b->left, smallest, index, kth); 
    
        (*index)++;
        if (*index == kth) {
            *smallest = b->value; 
        }
        
        InOrder(b->right, smallest, index, kth);
    }
    
}