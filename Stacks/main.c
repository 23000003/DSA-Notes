#include <stdio.h>
#include <stdbool.h>
#include "MyStack.h"

int main(){
	
	Stack s = createStack();
	
//	================ 1st Act ============
//	push(&s, 5);
//	visualize(s);
//	push(&s, 3);
//	visualize(s);
//	push(&s, 8);
//	visualize(s);
//	
//	Stack newStack = removeEven(&s);
//	visualize(newStack);
//	visualize(s);
//	void initStack(Stack *s);
//	Stack createStack();
//	bool isEmpty(Stack s);
//	bool isFull(Stack s);
//	void visualize(Stack s);
//	
//	bool push(Stack *s, int item);
//	bool pop(Stack *s);
//	int peek(Stack s);
//	
//	bool isFound(Stack s, int item);
//	Stack removeEven(Stack *s);


// ================ 2nd Act ===================
//Student createStudent(int studID, Name studName, String program, int year)
//	Name createName(String fname, String mname, String lname)

	push(&s, createStudent(12, createName("Kenny", "M", "Maratas"), "BSIT", 2));
	push(&s, createStudent(145, createName("Joe", "H", "Ermac"), "BSME", 2));
	push(&s, createStudent(1852, createName("Luke", "J", "Alvar"), "BSCE", 1));
	push(&s, createStudent(1852, createName("John", "M", "Doe"), "BSME", 1));
	(isFound(s, "Alvar")) ? printf("Found\n\n") : printf("Not Found\n\n");
	visualize(s);
	
	Name *students = getStudentInProgram(s, "BSME");
	visualizePart2(students);
	

	return 0;
}
