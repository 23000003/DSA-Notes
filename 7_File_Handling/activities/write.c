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

    FILE *fp;

    fp = fopen("person_file.dat", "wb");

    if(fp!=NULL){
        fwrite(list+2, sizeof(Person), 2, fp);
    }

    fclose(fp);

    
    return 0;
}