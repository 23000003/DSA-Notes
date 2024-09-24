#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10

// OPEN HASHING

typedef struct {
	int studID;
	char studName[20];
	bool sex; // t = M f = F
	char program[8];
	int level;
} Student;

typedef struct node{
	Student stud;
	struct node *next;
} NodeType, *NodePtr;

typedef struct {
	NodePtr elems[MAX];
	int count;
} Dictionary;

// count the number of one's bit in studID, first 3 letters of studName, entire letters of program and return with % MAX
int getHash(Student s);
void initDictionary(Dictionary *d);
bool addStudent(Dictionary *d, Student s);
bool removeStudent(Dictionary *d, Student s);
Student getStudent(Dictionary d, Student s);
void visualize(Dictionary s); // [0] = {id, name} [1] = (none if empty)
Student createStudent(int studID, char studName[], bool sex, char program[], int level);

int main(){
	
	Dictionary x;
	initDictionary(&x);
	
	addStudent(&x, createStudent(12, "Kenny", 0, "BSIT", 3));
	addStudent(&x, createStudent(17, "Kenwny", 0, "BSIT", 3));
	addStudent(&x, createStudent(3, "Kenwny", 0, "BSIT", 3));
	visualize(x);
	
	removeStudent(&x, createStudent(12, "Kenny", 0, "BSIT", 3));
	visualize(x);
	
	return 0;
}

int getHash(Student s){
	int i;
	
	for (i = 0; s.studID > 0 && s.studID & 1; i++, s.studID >>= 1){} // will recheck this
    
    int firstLetters = s.studName[0] + s.studName[1] + s.studName[2];
    
    int programLetters = 0;
    
    int countBit = i;
    
    for(i = 0; s.program[i] != '\0'; i++){
    	programLetters += s.program[i];
	}
    
    return (countBit + firstLetters + programLetters) % MAX;
}

void initDictionary(Dictionary *d){
	int i = 0;
	
	d->count = 0;
	for(i; i < MAX; i++){
		d->elems[i] = NULL;
	}
	
}

Student createStudent(int studID, char studName[], bool sex, char program[], int level){
	Student x;
	x.studID = studID;
	strcpy(x.studName, studName);
	strcpy(x.program, program);
	x.sex = sex;
	x.level = level;
	
	return x;
}

bool addStudent(Dictionary *d, Student s){
	int hashIndex = getHash(s);
	
	NodePtr store = malloc(sizeof(NodeType));
	store->next = NULL;
	store->stud = s;
	
	if(d->elems[hashIndex] == NULL){
		d->elems[hashIndex] = store;
		d->count++;
	}else{
		NodePtr *temp = &(d->elems[hashIndex]);
		
		while(*temp != NULL && (*temp)->stud.studID <= s.studID){
			if((*temp)->stud.studID != s.studID){
				printf("\nStudent Already Exists\n");
				return false;
			}
			temp = &(*temp)->next;	
		}
		
		store->next = *temp;
		*temp = store;
	}
	return true;
}

bool removeStudent(Dictionary *d, Student s){
	
	int hashIndex = getHash(s);
	
	
	if(d->elems[hashIndex] == NULL){
		printf("Empty Key\n");
		return false;
	}else{
		NodePtr *trav = &(d->elems[hashIndex]);
		
		while(*trav != NULL && (*trav)->stud.studID != s.studID){
			trav = &(*trav)->next;
		}
		
		if(*trav == NULL) return false;
		
		NodePtr del = *trav;
		*trav = (*trav)->next;
		
	}
	return true;
}

Student getStudent(Dictionary d, Student s){
	int hashIndex = getHash(s);
	
	if(d.elems[hashIndex] == NULL){
		printf("Empty Key\n");
		return;
	}else{
		NodePtr trav = d.elems[hashIndex];
		
		while(trav != NULL){
			if(trav->stud.studID == s.studID){
				return trav->stud;
			}
			trav = trav->next;
		}
	}
}

void visualize(Dictionary s){
	int i;
	for(i = 0; i < MAX; i++){
		printf("[%d] -> ", i);
		if(s.elems[i] != NULL){
			NodePtr trav = s.elems[i];
			while(trav != NULL){
				printf("ID: %d, Name: %s -> ", trav->stud.studID, trav->stud.studName);
				trav = trav->next;
			}
		}
		printf("\n");
	}
	printf("\n");
}















