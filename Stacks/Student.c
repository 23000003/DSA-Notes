//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include "MyStack.h"
//
//
//typedef char String[20];
//
//typedef struct{
//	String fname, mname, lname
//} Name;
//
//typedef struct{
//	int studID;
//	Name studName;
//	String program;
//	int year;
//}Student;
//
//typedef struct{
//	Student elems[MAX];
//	int count;
//}Stack;
//
//

void initStack(Stack *s){
	s->count = 0;
}

Stack createStack(){
	Stack myStack;
	initStack(&myStack);
	
	return myStack;
}

bool isEmpty(Stack s){
	
}

bool isFull(Stack s){
	
}

void visualize(Stack s){
	
}

bool push(Stack *s, Student stud){
	
}

bool pop(Stack *s){
	
}

int peek(Stack s){
	
}

bool isFound(Stack s, String lastname){
	
}

Name *getStudentInProgram(Stack s, String program){
	
}

Name createName(String fname, String mname, String lname){
	Name myName;
	strcpy(myName.fname, fname);
	strcpy(myName.mname, mname);
	strcpy(myName.lname, lname);
	
	return myName;
}

Student createStudent(int studID, Name studName, String program, int year){
	
	Student myStudent;
	myStudent.studID = studID;
	myStudent.studName = studName;
	strcpy(myStudent.program, program);
	myStudent.year = year;
	
	return myStudent;
}












