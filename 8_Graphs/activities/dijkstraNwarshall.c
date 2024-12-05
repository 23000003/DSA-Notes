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
void dijkstra(Graph a, char vertexStart, char vertexDestination);

//Warshall (Determine all shortest paths of all vertex's)
void floyd(Graph a);

int main(){

    Graph a;
    a.count = 0;
	int i;
    for (i = 0; i < MAX_CONNECTION; ++i){
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

	dijkstra(a, 'A', 'F');

    int *isVisited = calloc(MAX_CONNECTION, sizeof(int));

    printf("\nDFS: ");
    dfs(a, 'A', isVisited);

    int *isVisited1 = calloc(MAX_CONNECTION, sizeof(int));
    printf("\nBFS: ");
    bfs(a, 'A', isVisited1);

}


void insertEdge(Graph* a, char vertexFrom, char vertexTo, int weight){

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
	int i;
    for (i = 0; i < MAX_CONNECTION; ++i){
        printf("\n%c: ",i + 'A');
        
        for (trav = a.arr[i]; trav != NULL; trav = trav->link){
            printf("-> %c [%d] ",trav->data.vertex, trav->data.weight);
        }

    }
}

//djikstra (Determine shortest path of a vertext to a destination)
void dijkstra(Graph a, char vertexStart, char vertexDestination) {
    int *visited = calloc(MAX_CONNECTION, sizeof(int));
    int *distance = calloc(MAX_CONNECTION, sizeof(int)); // value of the shortest path

    Connection trav = a.arr[vertexStart - 'A'];
    Connection store = NULL;

    char smallestVertex;
    int small = 9999999;
    visited[vertexStart - 'A'] = 1;
    int pathCost = 0;

    while(1){
        
        if(trav != NULL){
            
        }
        // if(trav != NULL){
        //     if(trav->data.weight < small && visited[trav->data.vertex - 'A'] == 0){
        //         small = trav->data.weight;
        //         smallestVertex = trav->data.vertex;
        //     }

        //     if(trav->data.vertex == vertexDestination){
        //         pathCost += trav->data.weight;
        //         visited[trav->data.vertex - 'A'] = 1;
        //         break;
        //     }

        //     trav = trav->link;
        // }else{
        //     pathCost += small;
        //     small = 9999999;
        //     visited[smallestVertex - 'A'] = 1;
        //     // distance[smallestVertex - 'A'] = small;
        //     trav = a.arr[smallestVertex - 'A'];
        // }
    
    }


    printf("Shortest Path: ");
    for(int i = 0; i < MAX_CONNECTION; i++){
        if(visited[i] == 1){
            printf("%c -> ", i + 'A');
        }
    }

    printf("Cost: %d", pathCost);
}


// Use Queue 
void bfs(Graph a, char vertextStart, int isVisited[]){

    
}

// Use Stack (if no recursion)
void dfs(Graph a, char vertexStart, int isVisited[]){
   
}

