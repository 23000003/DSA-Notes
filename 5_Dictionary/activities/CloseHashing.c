#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

// Default packing density 80%

typedef enum {
	EMPTY = 0, 
	DELETED = 1
}Boolean;

typedef struct{
	int studID;
	char studName[16];
	char program[8];
	bool sex;
	int level;
} Student;

typedef struct {
	Student *data;
	int count;
	int max;
} StudDictionary;


int getHash(Student stud, int max);
void initDictionary(StudDictionary *dic);
bool insert(StudDictionary *dic, Student stud);
bool removeDic(StudDictionary *dic, Student stud);
Student getStud(Student dic);
void visualize(StudDictionary dic);
void reallocDic(StudDictionary *dic);

int main(){

	StudDictionary x;
	initDictionary(&x);
	
	Student s1 = {118, "Kenny", "BSIT", true, 2};
	insert(&x, s1);
	Student s2 = {111, "Kenny", "BSIT", true, 2};
	insert(&x, s2);
	Student s3 = {121, "Kenny", "BSIT", true, 2};
	insert(&x, s3);
	Student s4 = {131, "Kenny", "BSIT", true, 2};
	insert(&x, s4);
	Student s5 = {141, "Kenny", "BSIT", true, 2};
	insert(&x, s5);
	Student s6 = {151, "Kenny", "BSIT", true, 2};
	insert(&x, s6);
	Student s7 = {161, "Kenny", "BSIT", false, 2};
	insert(&x, s7);
	Student s8 = {171, "Kenny", "BSIT", true, 2};
	insert(&x, s8);
	Student s9 = {181, "Kenny", "BSIT", true, 2};
	insert(&x, s9);
	Student s10 = {191, "Kenny", "BSIT", true, 2};
	insert(&x, s10);
	removeDic(&x, s9);
	Student s11 = {211, "Kenny", "BSIT", true, 2};
	insert(&x, s11);
	visualize(x);
	
	removeDic(&x, s11);
	// visualize(x);
	return 0;
}

// ID from student add the position(index) of the bits ex. 1101 => gets 8 % Modulo
int getHash(Student stud, int max){
	
	int i, count = 0;
	for (i = 1; stud.studID > 0; i++, stud.studID = stud.studID >> 1){ 
	    if (stud.studID & 1){
	        count += i;
	    }
	}
		
	return count % max;
}

void initDictionary(StudDictionary *dic){
	
	dic->max = MAX;
	dic->count = 0;
	dic->data = malloc(sizeof(Student) * MAX);
	
	int i;
	for(i = 0; i < MAX; i++){
		dic->data[i].studID = 0;
	}
}

void reallocDic(StudDictionary *dic){
	
	Student temp[dic->max]; // can be a pointer pointing to dic->data
	int i, tempMax = dic->max;
	
	for(i = 0; i < dic->max; i++){
		temp[i] = dic->data[i];
	}

	dic->data = realloc(dic->data, sizeof(Student) * (dic->max += dic->max));
	dic->count = 0;

	for(i = 0; i < dic->max; i++){
		dic->data[i].studID = 0;
	}

	for(i = 0; i < tempMax; i++){
		insert(dic, temp[i]);
	} 
}


bool insert(StudDictionary *dic, Student stud){
	int hash = getHash(stud, dic->max);
	
	if(dic->count >= (dic->max * 0.80)){
		reallocDic(dic);
		printf("HEY");
	}	
	
	if(dic->data[hash].studID == 0){
		dic->data[hash] = stud;
	}else{
		for( ; dic->data[hash].studID != 0; hash = (hash + 1) % dic->max){
			if(dic->data[hash].studID == stud.studID){
				printf("ID already Exists\n\n");
				return false;
			}
		}
		dic->data[hash] = stud;
	}
	
	dic->count++;
	
	return true;
}

bool removeDic(StudDictionary *dic, Student stud){
	int hash = getHash(stud, dic->max);
	
	if(dic->data[hash].studID == 0) return false;
	
	for(; dic->data[hash].studID != stud.studID; hash = (hash + 1) % dic->max){
		if(dic->data[hash++].studID == 0){
			return false;
		}
	}
	dic->count--;
	dic->data[hash].studID = -1;
}

Student getStud(Student dic){
	return dic;
}

void visualize(StudDictionary dic){
	int i;
	int dens = dic.max * 0.80;
	printf("=== In Density ===\n");
	for(i = 0; i < dens; i++){
		if(dic.data[i].studID != 0 && dic.data[i].studID != -1){
			printf("[%d]: \n",i);
			Student s = getStud(dic.data[i]);
			printf("ID: %d\n",s.studID);
			printf("Name: %s\n", s.studName);
			printf("Program: %s\n",s.program);
			printf("Sex: %s\n", s.sex ? "Male" : "Female");
			printf("Level: %d\n\n", s.level);
		}else{
			printf("[%d]: %s\n\n", i, dic.data[i].studID == 0 ? "Empty" : "Deleted");
		}
	}
		
	printf("\n");
}










