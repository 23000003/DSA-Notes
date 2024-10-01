#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 0xA

typedef struct {
    char job[50];
} Person;

typedef struct node {
    char name[50];
    int gold;
    Person VIP[3];
    char distance[10];
} Town;

typedef struct {
    Town *elems; // #define MAX 0XA
    int front;
    int rear;
} Queue;


//Queue
Queue createQueue();
void initQueue(Queue *q);
bool enqueue(Queue *q, Town p);
bool dequeue(Queue *q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void display(Queue q);

// Functions
void deleteCriminalTowns(); // Function for Nobles. Delete Towns with...
void HuntCriminals(); // Function for Knights. Delete Towns that do not have... but have...
void deleteHighGoldTowns(); // Function for Merchants.
void sortTownsByDistance(); // Function to sort the list based on distance

// Just change the variables to Queue
int main(){ 
    
    printf("Prepare itinerary for? (Noble, Knight, Merchant): ");
    scanf("%s", input);

    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if (strcmp(input, "noble") == 0) {
        printf("\nYour Travel Plans, m'lord...\n\n");
        deleteCriminalTowns(&head);
        printTownNames(head);
    } else if (strcmp(input, "knight") == 0) {
        printf("\nCriminals found here good sir...\n\n");
        HuntCriminals(&head);
        printTownNames(head);
    } else if (strcmp(input, "merchant") == 0) {
        printf("\nOoooh Investments...\n\n");
        int budget;
        printf("Your gold:");
        scanf("%d", &budget);
        deleteHighGoldTowns(&head, budget);
        printTownNames(head);
    } else {
        printf("Invalid role entered.\n");
        head = NULL;
    }
}
