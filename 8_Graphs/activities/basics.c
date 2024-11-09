#include <stdio.h>
#include <stdlib.h>

#define MAX_CONNECTION 5

typedef struct{
    char vertex;
    int weight;
}Edge;

typedef struct node{
    Edge data;
    struct node *link;
}*Connection;

typedef struct{
    Connection arr[MAX_CONNECTION];
    int count;
}Graph;

typedef struct{
    Edge arr[MAX_CONNECTION][MAX_CONNECTION];
    int count;
}MatrixGraph;

void insertEdge(Graph* a, char vertexFrom, char vertexTo, int weight);
void display(Graph a);

//set isVisited to 1 if already visited if using recursion

// Use Queue
void bfs(Graph a, char vertextStart, int isVisited[]); // isVisited is redundant(?)

// Use Stack (if no recursion)
void dfs(Graph a, char vertexStart, int isVisited[]);  


int main(){

    Graph a;
    a.count = 0;

    for (int i = 0; i < MAX_CONNECTION; ++i){
        a.arr[i] = NULL;
    }

    insertEdge(&a, 'A', 'B', 8);
    insertEdge(&a, 'A', 'B', 5);
    insertEdge(&a, 'B', 'A', 3);
    insertEdge(&a, 'D', 'A', 3);
    insertEdge(&a, 'D', 'B', 1);
    insertEdge(&a, 'B', 'D', 3);
    insertEdge(&a, 'A', 'C', 84);
    insertEdge(&a, 'C', 'D', 3);
    insertEdge(&a, 'D', 'C', 4);
    insertEdge(&a, 'E', 'B', 4);
    insertEdge(&a, 'B', 'E', 4);
    insertEdge(&a, 'B', 'C', 3);
    insertEdge(&a, 'C', 'B', 3);
    insertEdge(&a, 'E', 'C', 3);
    insertEdge(&a, 'C', 'E', 3);

    display(a);

    int *isVisited = calloc(5, sizeof(int));

    printf("\nDFS: ");
    dfs(a, 'A', isVisited);
}


void insertEdge(Graph* a, char vertexFrom, char vertexTo, int weight){

    // ex. B - A = index 1 (inserting it sorted)
    Connection *trav = &(a->arr[vertexFrom - 'A']);


    for(; *trav != NULL;  trav = &(*trav)->link){
        if((*trav)->data.vertex == vertexTo){ // if vertex is the same then change weight and return
            (*trav)->data.weight = weight;
            return;
        } 
        if((*trav)->data.vertex > vertexTo) break; // insert sorted base on vertext
    }

    Edge createEdge = {vertexTo, weight};

    // Doesnt matter if trav is null it will still insert
    Connection store = malloc(sizeof(struct node));
    store->link = *trav;
    store->data = createEdge;
    *trav = store;
    a->count++;

}

void display(Graph a){
    Connection trav;

    for (int i = 0; i < MAX_CONNECTION; ++i){
        printf("\n%c: ",i + 'A');
        
        for (trav = a.arr[i]; trav != NULL; trav = trav->link){
            printf("-> %c [%d] ",trav->data.vertex, trav->data.weight);
        }

    }
}

// Use Queue
void bfs(Graph a, char vertextStart, int isVisited[]){
    
}

// Use Stack (if no recursion)
void dfs(Graph a, char vertexStart, int isVisited[]){
    isVisited[vertexStart - 'A'] = 1;
    
    printf("%c - ", vertexStart);

    for(Connection trav = a.arr[vertexStart - 'A']; trav != NULL; trav = trav->link){
        if(isVisited[trav->data.vertex - 'A'] != 1){
            dfs(a, trav->data.vertex, isVisited);
        }
    }
}

