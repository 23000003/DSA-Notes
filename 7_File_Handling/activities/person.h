#ifndef PERSON_H
#define PERSON_H

typedef struct{
    char name[20];
    int age;
}Person;

Person newPerson(char *name, int age);
void displayPerson(Person p);

#endif