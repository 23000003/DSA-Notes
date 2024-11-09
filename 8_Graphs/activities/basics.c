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
// ( will ask sir regarding if a vertex (vertexStart) is undirected (no connection) what to do)
void bfs(Graph a, char vertextStart, int isVisited[]){

    Queue q;
    q.rear = 0, q.front = 1;
    int countVisited = 1; // alrdy visits start

    isVisited[vertextStart - 'A'] = 1;
    printf("%c ", vertextStart);

    while(countVisited < MAX_CONNECTION){
        Connection trav;

        for(trav = a.arr[vertextStart - 'A']; trav != NULL; trav = trav->link){
            if(isVisited[trav->data.vertex - 'A'] != 1){
                q.rear = (q.rear + 1) % QueueMAX;
                // printf("\nVISITED %d\n", vertextStart - 'A');
                q.conn[q.rear] = trav->data;
                isVisited[trav->data.vertex - 'A'] = 1;
            }
        }
        if(((q.rear + 1) % QueueMAX) != q.front){
            printf("%c ", q.conn[q.front].vertex);
            vertextStart = q.conn[q.front].vertex;
            q.front = (q.front + 1) % QueueMAX;
            countVisited++;
        }

        // printf(">>%d<<", countVisited);
    }
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

