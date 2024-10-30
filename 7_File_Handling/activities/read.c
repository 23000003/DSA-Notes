#include <stdio.h>
#include <stdlib.h>
#include "person.h"

int main(){
    FILE *fp;
    Person p;

    fp = fopen("person_file.dat", "rb");

    if(fp!=NULL){
        while(fread(&p, sizeof(Person), 1, fp)){
            displayPerson(p);
            printf("\n");
        }
    }

    fclose(fp);

    return 0;
}