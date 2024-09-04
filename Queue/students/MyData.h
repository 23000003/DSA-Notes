#ifndef MYDATA_H
#define MYDATA_H

typedef struct{
	char fname[20];
	char lname[20];
}Name;

typedef struct{
	int studID;
	Name studName;
	char program[8];
	char sex;
}Student;

//transfer to myQueue.h

typedef Student Data;

typedef struct node{
	Data elem;
	struct node *link;
}NodeType, *NodePtr;

typedef struct{
	NodePtr head, tail;
}Queue;

void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
void display(Queue q);
void visualize(Queue q); // traversal

bool enqueue(Queue *q, Data d);
bool dequeue(Queue *q);
Data front(Queue q);

Name createName(char fname[], char lname[]);
Data createData(int studID, Name studName, char program[], char sex);

// gets the name of the student that matches with the program and sex,
// If program is an empty string then use all programs, if sexx is an empty character then get both sex
// use the concept of adding an empty string values for the name to use as a terminator for the name array
Name *getStudent(Queue q, char *program, char sex);

bool insertSorted(Queue *q, Data d); // insert the Data d based on lastname only 


#endif
