#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main(){
    Person list[5];

    list[0] = newPerson("Choi", 12);
    list[1] = newPerson("Derama", 20);
    list[2] = newPerson("Lui", 18);
    list[3] = newPerson("Gio", 21);
    list[4] = newPerson("Loyloy", 32);

    for(int i = 0; i<5; i++){
        displayPerson(list[i]);
        printf("\n");
    }

    return 0;
}