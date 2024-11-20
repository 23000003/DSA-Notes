#include <stdio.h>
#include <stdlib.h>

#define MAX_CONNECTION 6
#define QueueMAX 25

typedef struct{
    char vertex;
    int weight;
}Edge;

typedef struct{
    Edge arr[MAX_CONNECTION][MAX_CONNECTION];
    int count;
}MatrixGraph;

void insertEdge(MatrixGraph *m, Edge e);
void displayEdge(MatrixGraph m);
void dfs(MatrixGraph m);
void bfs(MatrixGraph m);

//djikstra (Determine shortest path of a vertext to a destination)
void dickstra(MatrixGraph a, char vertexStart, char vertexDestination);

//Warshall (Determine all shortest paths of all vertex's)
void floyd(MatrixGraph a);

int main(){

}

