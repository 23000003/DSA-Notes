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
    InsertSorted:
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


Legion createLegion(int legionNumber, char *legionType, Soldiers s);
Soldiers createSoldiers(int legionnaire, int centurion, int lightTroops, int archers);
void display(Stack s);
bool insertSorted(Stack *s, Legion leg);

int main(){
    Stack s;
    initStack(&s);
    push(&s, createLegion(7, "Cavalry", createSoldiers(1100, 55, 250, 200)));
    push(&s, createLegion(2, "Cavalry", createSoldiers(1200, 60, 300, 150)));
    push(&s, createLegion(1, "Infantry", createSoldiers(1000, 50, 200, 300)));
    push(&s, createLegion(6, "Infantry", createSoldiers(500, 20, 80, 50)));
    push(&s, createLegion(3, "Archers", createSoldiers(800, 40, 150, 80)));
    push(&s, createLegion(5, "Archers", createSoldiers(900, 35, 120, 1100)));
    push(&s, createLegion(8, "Archers", createSoldiers(600, 25, 100, 1200)));
    push(&s, createLegion(4, "Infantry", createSoldiers(700, 30, 100, 900)));
    // display(s);
    Stack ans;
    initStack(&ans);
    while(!isEmpty(s)){
        insertSorted(&ans, s.elems[--s.count]);
    }
    display(ans);
}

void initStack(Stack *s){
    s->count = 0;
    s->elems = malloc(sizeof(Legion) * MAX);
}

bool push(Stack *s, Legion leg){
    if(isFull(*s)) return false;

    s->elems[s->count++] = leg;

    return true;
}

bool pop(Stack *s){
    if(isEmpty(*s)) return false;

    s->count--;

    return true;
}

bool isEmpty(Stack s){
    return s.count == 0;
}
bool isFull(Stack s){
    return s.count == MAX;
}

bool resizeStack(Stack *s){
    s->elems = realloc(s->elems, sizeof(Legion) * (MAX + s->count));
    return true;
}

Legion peekLeg(Stack s){
    return s.elems[s.count - 1];
}

Soldiers peekSol(Legion l){
    return l.soldiers;
}


Legion createLegion(int legionNumber, char *legionType, Soldiers s){
    Legion l;
    l.legionNumber = legionNumber;
    strcpy(l.legionType, legionType);
    l.soldiers = s;

    return l;
}

Soldiers createSoldiers(int legionnaire, int centurion, int lightTroops, int archers){
    Soldiers s;
    s.archers = archers;
    s.legionnaire = legionnaire;
    s.centurion = centurion;
    s.lightTroops = lightTroops;

    return s;
}

void display(Stack s){

    printf("The Legions: \n");
    while(!isEmpty(s)){
        printf("Legion Number: %d, Legion Type: %s\n",s.elems[s.count - 1].legionNumber,s.elems[s.count - 1].legionType);
        printf("\tLegionnaire: %d, Centurion: %d, Light Troops: %d, Archers: %d\n\n", 
            s.elems[s.count - 1].soldiers.legionnaire, s.elems[s.count - 1].soldiers.centurion, 
            s.elems[s.count - 1].soldiers.lightTroops, s.elems[s.count - 1].soldiers.archers);
        pop(&s);
    }
}

bool insertSorted(Stack *s, Legion leg){
    if(isFull(*s)) return false;

    Stack hold;
    initStack(&hold);

    // while(!isEmpty(*s) && s->elems[s->count - 1].)

    if(strcmp(leg.legionType, "Cavalry") == 0){
        s->elems[s->count++] = leg;
        return true;
    }else if(strcmp(leg.legionType, "Cavalry") != 0 && leg.soldiers.archers > leg.soldiers.centurion &&
        leg.soldiers.archers > leg.soldiers.legionnaire && leg.soldiers.archers > leg.soldiers.lightTroops){
        while(!isEmpty(*s) && s->elems[s->count].soldiers.archers < leg.soldiers.archers){
            hold.elems[hold.count++] = s->elems[--s->count];
            printf("1\n");
        }
        s->elems[s->count++] = leg;
    }else{
        int found = 0;
        while(!isEmpty(*s)){
            if(strcmp(s->elems[s->count - 1].legionType, "Archers") == 0 && found == 0){
                hold.elems[hold.count++] = leg;
                found = 1;
            }else{
                hold.elems[hold.count++] = s->elems[--s->count];
            }
        }
    }

    while(!isEmpty(hold)){
        s->elems[s->count++] = hold.elems[--hold.count];
    }

    return true;
}

/*
    InsertSorted:
        Insert at the beginning if unit type is "Cavalry"
        Insert at the end if the Legion has a high count of Archers more than any other unit and is NOT of unit type "Cavalry"
        Else Insert before the first instance of the Legion type "Archers"
*/


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


