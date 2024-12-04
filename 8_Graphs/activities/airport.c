#include <stdio.h>
#include <stdlib.h>

#define MAX_FLIGHTS 100

// Define the structure for flights
typedef struct {
    int source;       // Source city
    int destination;  // Destination city
    int cost;         // Cost of the flight
} Flight;

// Define the structure for subsets (for Union-Find)
typedef struct {
    int parent;  // Parent of the subset
    int rank;    // Rank of the subset
} Subset;

// Function prototypes
int compareFlights(const void *a, const void *b); // Function to compare flights by cost
int find(Subset subsets[], int i);               // Function to find the root of a set
void unionSets(Subset subsets[], int x, int y);  // Function to union two sets
void kruskalMST(Flight flights[], int numFlights, int numCities); // Kruskal's MST algorithm

int main() {
    int numCities, numFlights;
    Flight flights[MAX_FLIGHTS];

    // Input the number of cities and flights
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    printf("Enter the number of flights: ");
    scanf("%d", &numFlights);

    // Input flight data
    for (int i = 0; i < numFlights; i++) {
        printf("Enter source, destination, and cost for flight %d: ", i + 1);
        scanf("%d %d %d", &flights[i].source, &flights[i].destination, &flights[i].cost);
    }

    // Call Kruskal's algorithm to find the MST
    kruskalMST(flights, numFlights, numCities);

    return 0;
}

// Function to compare flights by their cost (used in sorting)
int compareFlights(const void *a, const void *b) {
    Flight *flightA = (Flight *)a;
    Flight *flightB = (Flight *)b;
    
    return flightA->cost - flightB->cost;
}

// Function to find the root of a set (with path compression)
int find(Subset subsets[], int i) {
    // TODO: Implement find with path compression
    
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to union two sets (by rank)
void unionSets(Subset subsets[], int x, int y) {
    // TODO: Implement union by rank
    
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    
    if(subsets[rootX].rank < subsets[rootY].rank){
        subsets[rootX].parent = rootY;
    } else if(subsets[rootX].rank > subsets[rootY].rank){
        subsets[rootY].parent = rootX;
    }else{
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
    
}
// // Define the structure for flights
// typedef struct {
//     int source;       // Source city
//     int destination;  // Destination city
//     int cost;         // Cost of the flight
// } Flight;

// // Define the structure for subsets (for Union-Find)
// typedef struct {
//     int parent;  // Parent of the subset
//     int rank;    // Rank of the subset
// } Subset;
// Function to compute the MST using Kruskal's algorithm
void kruskalMST(Flight flights[], int numFlights, int numCities) {
    // TODO: Sort flights by cost
    for(int i = 0; i < numFlights - 1; i++){
        for(int j = 0; j < numFlights - 1; j++){
            if(compareFlights(&flights[j], &flights[j+1]) > 0){
                Flight temp = flights[j];
                flights[j] = flights[j+1];
                flights[j+1] = temp;
            }
        }
    }
    // TODO: Initialize subsets
    Subset s[numCities];
    for(int i = 0; i < numCities; i++){
        s[i].parent = i;
        s[i].rank = 0;
    }
    
    Flight fl[numCities - 1];
    int count = 0;
    
    int minCost = 0;
    // TODO: Iterate through sorted flights and construct the MST
    for(int i = 0; i < numFlights; i++){
        int v1 = find(s, flights[i].source); 
        int v2 = find(s, flights[i].destination); 
        int wt = flights[i].cost; 
    
        if (v1 != v2) { 
            unionSets(s, v1, v2); 
            minCost += wt;
            fl[count++] = flights[i];        
        } 
    }
    
    // int isMST = 1;
    // int parent = s[0].parent;
    // for(int i = 1; i < numCities; i++){
    //     if(s[i].parent != parent){
    //         isMST = 0;
    //     }
    // }
    
    if(count != numCities-1){
        printf("The graph is not fully connected; MST cannot be formed.");
    }else{
        printf("Minimum Spanning Tree:\n");
        for(int i = 0; i < count; i++){
            printf("Edge: %d - %d, Cost: %d\n", fl[i].source, fl[i].destination, fl[i].cost);
        }
        
        printf("Total cost of the MST: %d\n", minCost); 
        // TODO: Print the MST and total cost
    }
    
    
    // printf("Minimum Spanning Tree:\n");
    // for(int i = 0; i < count; i++){
    //     printf("Edge: %d - %d, Cost: %d\n", fl[i].source, fl[i].destination, fl[i].cost);
    // }
    
    // printf("Total cost of the MST: %d\n", minCost); 
    // // TODO: Print the MST and total cost
    
    
}
