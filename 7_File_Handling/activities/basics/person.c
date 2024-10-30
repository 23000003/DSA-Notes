#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"


Person newPerson(char *name, int age){
    Person p;

    strcpy(p.name, name);
    p.age = age;

    return p;
}

void displayPerson(Person p){
    printf("%-20s - %d", p.name, p.age);
}