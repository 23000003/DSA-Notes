#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTREE 20

typedef struct node{
    struct node *left, *right;
    int val;
}*BSTLL;

typedef struct{
    int elems[MAXTREE];
    int last;
}POT, BSTArr; // use last in BSTArr as count

// MAX HEAP
void insertPOT(POT *p, int val);
void deletePOT(POT *p);

void insertBSTArr(BSTArr *a, int val);
void deleteBSTArr(BSTArr *a); // root
void deleteBSTArrItem(BSTArr *a, int item);

void insertBSTLL(BSTLL *b, int val);
void deleteBSTLL(BSTLL *b); // root
void deleteBSTLLitem(BSTLL *b, int item);

void preOrderArr(BSTArr a);
void postOrderArr(BSTArr a);
void inOrderArr(BSTArr a);
void postOrderLL(BSTLL b);
void preOrderLL(BSTLL b);
void inOrderLL(BSTLL b);

int main(){
    
    POT p;
    p.last = 0;

    insertPOT(&p, 5);
    insertPOT(&p, 6);
    insertPOT(&p, 7);
    insertPOT(&p, 2);
    insertPOT(&p, 1);
    insertPOT(&p, 9);
    deletePOT(&p);

    printf("==========================\n");
    for(int i = 0; i < p.last; i++){ // breadorder
        printf("%d ", p.elems[i]);
    }

    // =====================================

    BSTArr a;
    a.last = 0;

    for(int i = 0; i < MAXTREE; i++){ // initialize
        a.elems[i] = 0;
    }

    insertBSTArr(&a, 5);
    insertBSTArr(&a, 6);
    insertBSTArr(&a, 7);
    insertBSTArr(&a, 2);
    insertBSTArr(&a, 1);
    insertBSTArr(&a, 9);
    insertBSTArr(&a, 3);

    printf("\n==========================\n");
    for(int i = 0; i < MAXTREE; i++){ // breadorder
        printf("%d ", a.elems[i]);
    }

    // =====================================

    BSTLL b = NULL;

    return 0;
}



void insertPOT(POT *p, int val){
    
    if(p->last >= MAXTREE) return;

    int i;
    for(i = p->last; p->elems[(i - 1) / 2] < val && i != 0; i = ( i - 1 ) / 2){
        p->elems[i] = p->elems[(i - 1) / 2];
    }
    p->elems[i] = val;
    p->last++;
}

void deletePOT(POT *p){

    int i;
    p->last--;

    for(i = 0; i <= p->last && 
        (p->elems[p->last] < p->elems[(i * 2) + 1] || p->elems[p->last] < p->elems[(i * 2) + 2])
    ; ){
        int left = (i * 2) + 1;
        int right = (i * 2) + 2;

        if(left <= p->last || right <= p->last){
            if(p->elems[right] > p->elems[left] && right <= p->last){
                p->elems[i] = p->elems[right];
                i += right;
            }else{
                p->elems[i] = p->elems[left];
                i += left;
            }
        }else{
            break;
        }
    }

    p->elems[i] = p->elems[p->last];
}

void insertBSTArr(BSTArr *a, int val){

    int i = 0;
    
    while(a->elems[i] != 0){
        if(a->elems[i] == val) return;
        i = (a->elems[i] > val) ?  (i * 2) + 1 : (i * 2) + 2; 
    }

    a->elems[i] = val;
    a->last++;
}

void deleteBSTArr(BSTArr *a){

}

void deleteBSTArrItem(BSTArr *a, int item){

}

void insertBSTLL(BSTLL *b, int val){

    BSTLL store = calloc(1, sizeof(struct node));
    store->val = val;

    while(*b != NULL){
        if((*b)->val == val) return;
        b = ((*b)->val > val) ? &(*b)->left : &(*b)->right;
    }

    *b = store;
}

void deleteBSTLL(BSTLL *b){

}

void deleteBSTLLitem(BSTLL *b, int item){

}

// ====================

void inOrderLL(BSTLL b){

}

void postOrderLL(BSTLL b){

}

void preOrderLL(BSTLL b){

}

// ===================== 

void inOrderArr(BSTArr a){

}

void postOrderArr(BSTArr a){

}

void preOrderArr(BSTArr a){

}


// void PostOrder(BST bst){
//     if(bst != NULL){
//         PostOrder(bst->left);
//         PostOrder(bst->right);
//         printf("%d ", bst->data);
//     }    
// }

// void PreOrder(BST bst){
//     if(bst != NULL){
//         printf("%d ", bst->data);
//         PreOrder(bst->left);
//         PreOrder(bst->right);
//     }  
// }

// void InOrder(BST bst){
//     if(bst != NULL){
//         InOrder(bst->left);
//         printf("%d ", bst->data);
//         InOrder(bst->right);
//     }    
// }
