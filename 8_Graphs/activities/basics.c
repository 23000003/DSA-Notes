#include <stdio.h>
#include <stdlib.h>

#define MAX_GRAPH 10

typedef struct{
    char vertex;
    int weight;
}Edge;

typedef struct node{
    Edge data;
    struct node *link;
}*Connection;

typedef struct{
    Connection arr[MAX_GRAPH];
    int count;
}Graph;

void insertEdge(Graph* a, char vertexFrom, char vertexTo, int weight);
void display(Graph a);

//set isVisited to 1 if already visited if using recursion

// Use Queue
void bfs(Graph a, char vertextStart, int isVisited[]); // isVisited is redundant(?)

// Use Stack (if no recursion)
void dfs(Graph a, char vertexStart, int isVisited[]);  
