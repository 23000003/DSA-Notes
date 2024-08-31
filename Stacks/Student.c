#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "MyStack.h"
#define MAX 5

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
	return s.count == 0;
}

bool isFull(Stack s){
	return s.count == MAX;	
}

void visualize(Stack s){
	int i;
	for(i = 0; i < s.count; i++){
		printf("Student %d:\n", i+1);
		printf("Student ID: %d\n", s.elems[i].studID);
		printf("Full Name: %s %s. %s\n", s.elems[i].studName.fname, s.elems[i].studName.mname, s.elems[i].studName.lname);
		printf("Program and Year: %s %d\n\n", s.elems[i].program, s.elems[i].year);
	}	
}

void visualizePart2(Name *s){
	int i;
	printf("======= Students with the same program ========\n");
	for(i = 0; strcmp(s[i].fname, " ") != 0; i++){
		printf("Student %d:\n", i+1);
		printf("Full Name: %s %s. %s\n\n", s[i].fname, s[i].mname, s[i].lname);
	}	
}

bool push(Stack *s, Student stud){
	if(isFull(*s)) return false;
	
	s->elems[s->count++] = stud;
	
	return true;
}

bool pop(Stack *s){
	if(isEmpty(*s)) return false;
	
	s->count--;
}

String *peek(Stack s, bool type){ // if type = true then return lastname if type = false then program (this is for isFound and getStudentInProgram)
	if(isEmpty(s)) return;

	return type == true ? s.elems[s.count - 1].studName.lname : s.elems[s.count - 1].program;
}

bool isFound(Stack s, String lastname){
	
	if(isEmpty(s)) return false;
	
	while(!isEmpty(s)){
		if(strcmp(peek(s, true), lastname) == 0){
			return true;
		}
		pop(&s);
	}
	return false;
}

Name *getStudentInProgram(Stack s, String program){
	
	if(isEmpty(s)) return false;
	
	Name *students = malloc(sizeof(Name) * s.count + 1);
	int i = 0;
	while(!isEmpty(s)){
		if(strcmp(peek(s, false), program) == 0){
			students[i++] = s.elems[s.count - 1].studName;
		}
		pop(&s);
	}
	strcpy(students[i].fname, " ");
	
	return students;
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












