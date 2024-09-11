#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct{
    int elems[MAX];
    int count;
}Set;


Set createSet();
bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDifferenceSet(Set a, Set b); //(A - B) U (B - A)
int cardinality(Set a);
bool isElement(Set s, int item);

int main(){
    Set a = createSet();
    Set b = createSet();
    
    (addElement(&a, 2) ? printf("Success\n") : printf("Failed\n"));
    (addElement(&a, 5) ? printf("Success\n") : printf("Failed\n"));
    (addElement(&b, 2) ? printf("Success\n") : printf("Failed\n"));
    (addElement(&b, 4) ? printf("Success\n") : printf("Failed\n"));
    
    displaySet(a);
    displaySet(b);
    Set myUnion = unionSet(a, b);
    printf("\nUnion: ");
    displaySet(myUnion);
    
    Set myIntersect = intersectionSet(a, b);
    printf("\nIntersect: ");
    displaySet(myIntersect);
    
    Set myDiff = differenceSet(a, b);
    printf("\nDifference Set A: ");
    displaySet(myDiff);

    Set myDiff2 = differenceSet(b, a);
    printf("\nDifference Set B: ");
    displaySet(myDiff2);
    
    Set mySymm = symmetricDifferenceSet(a, b);
    printf("\nSymmetric: ");
    displaySet(mySymm);
    
    printf("\nCardinality: %d", cardinality(a));
    printf("\nisElement: %d", isElement(a, 5));
}


Set createSet(){
    Set mySet;
    mySet.count = 0;
    for(int i = 0; i < MAX; i++){
        mySet.elems[i] = 0;
    }
    return mySet;
}

bool addElement(Set *s, int item){
    if(s->count == MAX) return false;
    
    if(s->elems[item] == 1){
        printf("Already exists\n");
        return false;
    }
    
    s->elems[item] = 1;
    s->count++;
    
    return true;
}

bool removeElement(Set *s, int item){
    if(s->count == 0) return false;
    s->count--;
    return true;
}

void displaySet(Set s){
    
    int isDone, i;
    printf("\n");
    for(i = 0, isDone = 0; i < MAX && isDone != s.count; i++){
        if(s.elems[i] == 1){
            printf("%d ", i);
            isDone++;
        }
    }
}

Set unionSet(Set a, Set b){
    Set s = createSet();
    
    int greater = (a.count > b.count) ? a.count + 1 : b.count + 1;
    for(int i = 0; i < MAX && s.count != greater; i++){
        if(a.elems[i] == 1 || b.elems[i] == 1){
            s.elems[i] = 1;
            s.count++;
        }    
    }
    
    return s;
}

Set intersectionSet(Set a, Set b){
    Set s = createSet();
    
    int greater = (a.count > b.count) ? a.count + 1 : b.count + 1;
    for(int i = 0; i < MAX && s.count != greater; i++){
        if(a.elems[i] == 1 && b.elems[i] == 1){
            s.elems[i] = 1;
            s.count++;
        }    
    }
    
    return s;
}

Set differenceSet(Set a, Set b){
    Set s = createSet();
    
    int greater = (a.count > b.count) ? a.count + 1 : b.count + 1;
    for(int i = 0; i < MAX && s.count != greater; i++){
        if((a.elems[i] == 1 && b.elems[i] == 0)){
            s.elems[i] = 1;
            s.count++;
        }    
    }
    
    return s;
}

Set symmetricDifferenceSet(Set a, Set b){
    Set s = createSet();
    
    int greater = (a.count > b.count) ? a.count + 1 : b.count + 1;
    for(int i = 0; i < MAX && s.count != greater; i++){
        if((a.elems[i] != b.elems[i])){
                
            s.elems[i] = 1;
            s.count++;
        }    
    }
    
    return s;
}

int cardinality(Set a){
    return a.count;
}

bool isElement(Set s, int item){
    return s.elems[item] == 1;
}