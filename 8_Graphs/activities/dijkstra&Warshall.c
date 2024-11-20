#include <stdio.h>
#include <stdlib.h>

#define MAX_CONNECTION 6
#define QueueMAX 25

typedef struct{
    char vertex;
    int weight;
}Edge;

typedef struct{
    Edge conn[QueueMAX];
    int rear, front;
}Queue;

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


//djikstra (Determine shortest path of a vertext to a destination)
void dickstra(Graph a, char vertexStart, char vertexDestination);

//Warshall (Determine all shortest paths of all vertex's)
void floyd(Graph a);

int main(){

    Graph a;
    a.count = 0;

    for (int i = 0; i < MAX_CONNECTION; ++i){
        a.arr[i] = NULL;
    }

    insertEdge(&a, 'A', 'B', 8);
    insertEdge(&a, 'A', 'B', 5);
    insertEdge(&a, 'A', 'E', 5);

    insertEdge(&a, 'B', 'A', 3);
    insertEdge(&a, 'B', 'C', 7);
    insertEdge(&a, 'B', 'D', 4);

    insertEdge(&a, 'C', 'D', 4);
    insertEdge(&a, 'C', 'B', 4);

    insertEdge(&a, 'D', 'E', 3);
    insertEdge(&a, 'D', 'B', 1);
    insertEdge(&a, 'D', 'C', 3);
    insertEdge(&a, 'D', 'F', 3);

    insertEdge(&a, 'E', 'D', 3);
    insertEdge(&a, 'E', 'F', 3);

    insertEdge(&a, 'F', 'D', 3);
    insertEdge(&a, 'F', 'E', 3);

    //bug if a vertex doesnt have a connection = infinite loop

    display(a);

    int *isVisited = calloc(MAX_CONNECTION, sizeof(int));

    printf("\nDFS: ");
    dfs(a, 'A', isVisited);

    int *isVisited1 = calloc(MAX_CONNECTION, sizeof(int));
    printf("\nBFS: ");
    bfs(a, 'A', isVisited1);

}


void insertEdge(Graph* a, char vertexFrom, char vertexTo, int weight){

    

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
   
}

