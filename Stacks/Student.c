#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MyStack.h"


typedef char String[20];

typedef struct{
	String fname, mname, lname
} Name;

typedef struct{
	int studID;
	Name studName;
	String program;
	int year;
}Student;

typedef struct{
	Student elems[MAX];
	int count;
}Stack;


void initStack(Stack *s);
Stack createStack();
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);

bool push(Stack *s, Student stud);
bool pop(Stack *s);
int peek(Stack s);

bool isFound(Stack s, String lastname);
Name *getStudentInProgram(Stack s, String program);
Name createName(String fname, String mname, String lname);
Student createStudent(int studID, Name studName, String program, int year);

