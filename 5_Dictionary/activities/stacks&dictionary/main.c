#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

/**CREATE A FUNCTION THAT CONVERTS A PRODUCT STACK
 * INTO A DICTIONARY. IF SIMILAR PRODUCT EXISTS,
 * AUTOMATICALLY ADDS IT INTO prodQTY
 */

/**70% LOAD FACTOR / PACKING DENSITIY */

typedef struct {
    int prodID;
    char prodName[16];
    int prodQty;
    float prodPrice;
} Product;

typedef struct node {
    Product prod;
    struct node *next;
} NodeType, *NodePtr, *Stack;

typedef struct {
    NodePtr *data; // dynamic array
    int count;
    int max;
} ProdDict;

// Stack
bool push(Stack *s, Product prod);
bool pop(Stack *s);
Product peek(Stack s);
bool isEmpty(Stack s);
void initStack(Stack *s);

// Dictionary
int getHash( Product p);
bool add(ProdDict *dict, Product p);
bool remove(ProdDict *dict, Product p);
void initDict(ProdDict *dict);

int main(){

}



// Stack
bool push(Stack *s, Product prod){

    Stack temp = malloc(sizeof(struct node));
    temp->next = *s;
    temp->prod = prod;
    *s = temp;

    return true;
}

bool pop(Stack *s){
    if(isEmpty(*s)) return false;

    Stack del = *s;
    *s = (*s)->next;
    free(del);

    return true;
}

Product peek(Stack s){
    return s->prod;
}

bool isEmpty(Stack s){
    return s == NULL;
}

void initStack(Stack *s){
    *s = NULL;
}


// Dictionary
int getHash(Product p){ 
    int count = 0;
    for(int i = 1; p.prodID > 0; p.prodID >>= 1){ //base on index
        if(p.prodID & 1){
            count += i;
        }
    }

    int x = p.prodName[0] + p.prodName[1] + p.prodName[2] + p.prodName[3] + p.prodName[4];

    return (x + count) % MAX;
}

bool add(ProdDict *dict, Product p){
    
}

bool remove(ProdDict *dict, Product p){

}

void initDict(ProdDict *dict){
    dict->count = 0;
    dict->data = malloc(sizeof(struct node) * MAX);
    dict->max = MAX;

    for(int i = 0; i < MAX; i++){
        dict->data[i] = NULL;
    }
}
