#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 0XA

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
bool removeD(ProdDict *dict, Product p);
void initDict(ProdDict *dict);

bool convertStacktoDict(ProdDict *dict, Stack s);
Product createProduct(int prodID, char prodName[], int prodQty, float prodPrice);
void visualizeStack(Stack s);
void visualizeDict(ProdDict dict);

int main(){
    Stack s;
    initStack(&s);

    ProdDict dic;
    initDict(&dic);

    push(&s, createProduct(10, "Candy", 3, 3.22));
    push(&s, createProduct(20, "Chocolate", 7, 52.2));
    push(&s, createProduct(30, "Barbecue", 4, 7.62));
    push(&s, createProduct(30, "Barbecue", 4, 7.62));
    push(&s, createProduct(14, "TESTTT", 4, 7.62));
    push(&s, createProduct(7, "TESTTT1111111111111", 4, 7.62));
    // visualizeStack(s);
    
    convertStacktoDict(&dic, s);
    visualizeDict(dic);

    removeD(&dic, createProduct(10, "Candy", 3, 3.22));
    visualizeDict(dic);
    
    return 0;
}

Product createProduct(int prodID, char prodName[], int prodQty, float prodPrice){
    Product p;
    p.prodID = prodID;
    p.prodQty = prodQty;
    p.prodPrice = prodPrice;
    strcpy(p.prodName, prodName);

    return p;
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

bool convertStacktoDict(ProdDict *dict, Stack s){

    if(isEmpty(s)) return false;

    while(!isEmpty(s)){
        add(dict, peek(s));
        // pop(&s);
        Stack del = s;
        s = s->next;
        free(del);
    }

}

// InsertSorted (if similar ID exists then add prodQTY)
bool add(ProdDict *dict, Product p){
    int hash = getHash(p);

    printf("\n===%d===\n", hash);
    if(dict->count >= (dict->max * 0.70)) return false;

    Stack *temp = &(dict->data[hash]);

    while(*temp != NULL && (*temp)->prod.prodID <= p.prodID){
        if((*temp)->prod.prodID == p.prodID){
            (*temp)->prod.prodQty += p.prodQty;
            return true;    
        }
        temp = &(*temp)->next;
    }

    NodePtr store = malloc(sizeof(NodeType));
    store->next = *temp;
    store->prod = p;
    *temp = store;

    return true;
}

bool removeD(ProdDict *dict, Product p){
    int hash = getHash(p);

    if(dict->data[hash] == NULL) return false;

    Stack *temp = &(dict->data[hash]);

    for(;*temp != NULL && (*temp)->prod.prodID != p.prodID; temp = &(*temp)->next){}

    if(*temp == NULL){
        printf("Item Not Found");
        return false;
    }else{
        NodePtr del = *temp;
        *temp = (*temp)->next;
        free(del);
        return true;
    }
}

void initDict(ProdDict *dict){
    dict->count = 0;
    dict->data = malloc(sizeof(struct node) * MAX);
    dict->max = MAX;

    for(int i = 0; i < MAX; i++){
        dict->data[i] = NULL;
    }
}


void visualizeDict(ProdDict dict){
    
    printf("\n====== Dictionary: ========\n");
    for(int i = 0; i < dict.max; i++){
        NodePtr trav = dict.data[i];
        printf("\nProduct [%d]:  => ", i);
        if(trav == NULL){
            printf("Empty.\n");
        }else{
            while(trav != NULL){
                Product p = peek(trav);
                printf(" ID: %d =>", p.prodID);
                // printf("\nName: %s", p.prodName);
                // printf("\nQuantity: %d", p.prodQty);
                // printf("\nPrice: %f\n", p.prodPrice);
                trav = trav->next;
            }
            printf("\n");
        }
    }
    printf("\n");

}

void visualizeStack(Stack s){
    printf("\n ========= Stack: ==========\n");
    while(s != NULL){
        Product p = peek(s);
        printf("\nID: %d", p.prodID);
        printf("\nName: %s", p.prodName);
        printf("\nQuantity: %d", p.prodQty);
        printf("\nPrice: %f\n", p.prodPrice);
        s = s->next;
    }
    printf("\n");
}


// typedef struct {
//     int prodID;
//     char prodName[16];
//     int prodQty;
//     float prodPrice;
// } Product;

// typedef struct node {
//     Product prod;
//     struct node *next;
// } NodeType, *NodePtr, *Stack;

// typedef struct {
//     NodePtr *data; // dynamic array
//     int count;
//     int max;
// } ProdDict;
