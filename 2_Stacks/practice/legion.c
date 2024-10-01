#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 0XA


typedef struct {
    int legionnaire;
    int centurion;
    int lightTroops;
    int archers;
} Soldiers;

typedef struct node {
    int legionNumber;
    char legionType[20];
    Soldiers soldiers;
}Legion;


typedef struct {
    Legion *elems;
    int count;
}Stack;


/*
    Push:
        Insert at the beginning if unit type is "Cavalry"
        Insert at the end if the Legion has a high count of Archers more than any other unit and is NOT of unit type "Cavalry"
        Else Insert before the first instance of the Legion type "Archers"
*/

void initStack(Stack *s);
bool push(Stack *s, Legion leg);
bool pop(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
bool resizeStack(Stack *s);
Legion peekLeg(Stack s);
Soldiers peekSol(Legion l);



// TEST CASE (Display)

// The Legions:
// Legion Number: 7, Legion Type: Cavalry
//   Legionnaire: 1100, Centurion: 55, Light Troops: 250, Archers: 200

// Legion Number: 2, Legion Type: Cavalry
//   Legionnaire: 1200, Centurion: 60, Light Troops: 300, Archers: 150

// Legion Number: 1, Legion Type: Infantry
//   Legionnaire: 1000, Centurion: 50, Light Troops: 200, Archers: 300

// Legion Number: 6, Legion Type: Infantry
//   Legionnaire: 500, Centurion: 20, Light Troops: 80, Archers: 50

// Legion Number: 3, Legion Type: Archers
//   Legionnaire: 800, Centurion: 40, Light Troops: 150, Archers: 80

// Legion Number: 4, Legion Type: Infantry
//   Legionnaire: 700, Centurion: 30, Light Troops: 100, Archers: 900

// Legion Number: 5, Legion Type: Archers
//   Legionnaire: 900, Centurion: 35, Light Troops: 120, Archers: 1100

// Legion Number: 8, Legion Type: Archers
//   Legionnaire: 600, Centurion: 25, Light Troops: 100, Archers: 1200


