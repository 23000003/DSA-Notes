#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 0xF

/**
 * generateInfo = is what creates for your studInfo Base on the bits of the variable (generateInfo)
 * how to get generateInfo? => from "studName id" (why?, because it automatically truncates to % 256 since its unsigned char)
 */

/*Given 8 bits: 0000 0000
 
 Bits
 8    = Status:            0 - Inactive, 1 - Active
 7    = Nationality:       0 - Filipino, 1 - Foreigner
 6    = Enrollment Status: 0 - Regular, 1 - Irregular
 5    = Gender:            0 - Male, 1 - Female
 3-4  = Year Level:        00 - 1st, 01 - 2nd, 10 - 3rd, 11 - 4th
 1-2  = Program:           00 - CS, 01 - IT, 10 - IS, 11 - MATH
 
 For example:
 1001 1001 would represent an Active Regular 3rd Year Filipino Female IT Student
*/

/**
 * ## Hashing:
 * Open Hashing
 * hash = Number of zero bits in the id variable
 * 
 * ## Queue
 * Insert Sorted
 */

typedef enum {EMPTY = 0, DELETED = 1}Boolean;

typedef struct{
    int status;
    char nationality[MAX];
    int enrollmentStatus;
    int gender;
    char yearLevel[MAX];
    char program[MAX];
}StudInfo;

typedef struct{
    int id;
    char fName[64];
    char mi;
    char lName[32];
    StudInfo info;
}StudName;

typedef unsigned char GenerateInfo;

typedef struct node{
    StudName stud;
    struct node *next;
}NodeType, *NodePtr;

typedef struct{
    NodePtr head;
    NodePtr tail;
}Queue;

typedef Queue PersonDict[MAX]; // Open Hashing

typedef StudName HigherDict[MAX]; // Closed Hashing // use id for empty and deleted


// Queue
void initQueue(Queue *q);
Queue createQueue();
bool isEmpty(Queue q);
bool enqueue(Queue *q, StudName s);
bool dequeue(Queue *q);
void displayQueue(Queue q);
StudName createStudent(int id, char *fName, char mi, char *lName);
StudName front(Queue q);

/**
 * CreateInfo Function::
 * generateInfo = is what creates for your studInfo Base on the bits of the variable (generateInfo)
 * how to get generateInfo? => from "studName id" (why?, because it automatically truncates to % 256 since its unsigned char)
 */
StudInfo createInfo(int studID); // refer to top


//Dictionary
int getHash(int id); // Number of zero bits in the id variable
// For Open Hashing
void initDict(PersonDict *dic);
bool insertDic(PersonDict *dic, StudName st);
bool removeDic(PersonDict *dic, StudName st);

//For Closed Hashing
void resize(HigherDict *dic);
void initDict2(HigherDict *dic);
bool insertDict2(HigherDict *dic, StudName st);
bool removeDic2(HigherDict *dic, StudName st);

// To Do Functions 
HigherDict *convertToHigherDict(PersonDict dic); // transfer to HigherDict if dic contains yearLevel 3 and up (dont delete)
Queue *removeInactiveStudents(PersonDict D);   // returns a Queue of inactive students and deletes them in the dictionary
char* getProgram(PersonDict dic, int key, char *program);  //Returns the string equivalent of the program of the given key (hash)


int main(){
    
}



// Queue
void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
}

Queue createQueue(){
    Queue q;
    initQueue(&q);

    return q;
}

bool isEmpty(Queue q){
    return q.head == NULL;
}

bool enqueue(Queue *q, StudName s){

    NodePtr temp = malloc(sizeof(NodeType));
    temp->next = NULL;
    temp->stud = s;
    
    if(q->head == NULL && q->tail == NULL){
        q->head = temp;
        q->tail = temp;
    }else{
        q->tail->next = temp;
        q->tail = temp;
    }

    return true;
}

bool dequeue(Queue *q){
    if(isEmpty(*q)) return false;

    NodePtr *del = q->head;
    q->head = q->head->next;
    free(del);

    return true;
}

void displayQueue(Queue q){

}

StudName createStudent(int id, char *fName, char mi, char *lName){
    StudName s;
    s.id = id;
    s.mi = mi;
    strcpy(s.fName, fName);
    strcpy(s.lName, lName);
    s.info = createInfo(id);

    return s;
}

/**
 * CreateInfo Function::
 * generateInfo = is what creates for your studInfo Base on the bits of the variable (generateInfo)
 * how to get generateInfo? => from "studName id" (why?, because it automatically truncates to % 256 since its unsigned char)
 */

StudInfo createInfo(int studID){
    StudInfo s;

    GenerateInfo info = studID;

    // int value = 0;
    // for(int i = 1; info > 0; info >>= 1){
    //     value += info 
    // }
}

//Dictionary
int getHash(int id){
    int sum = 0;
    for(int i = 0; i < 32; i++, id >>= 1){
        if((id & 1) == 0){
            sum++;
        }
    }
    return sum;
}

// For Open Hashing
void initDict(PersonDict *dic){
    for(int i = 0; i < MAX; i++){
        dic[i]->head = NULL;
        dic[i]->tail = NULL;
    }
}

StudName front(Queue q){
    return q.head->stud;
}

bool insertDic(PersonDict *dic, StudName st){

    int hash = getHash(st.id);

    NodePtr temp = malloc(sizeof(NodeType));
    temp->next = NULL;
    temp->stud = st;

    if(dic[hash]->tail == NULL){
        dic[hash]->tail = temp;
        dic[hash]->head = temp;
    }else{
        Queue store = createQueue();
        int identify = 0;
        while(dic[hash]->head != NULL){
            if(dic[hash]->head->stud.id < st.id && identify == 0){
                if(store.tail != NULL){
                    store.tail->next = temp;
                }
                store.tail = temp; 
                temp->next = dic[hash]->head;
                identify = 1;
            }else{
                store.tail = dic[hash]->head;
                dic[hash]->head = dic[hash]->head->next;
            }
            if(store.head == NULL){
                store.head = store.tail;
            }
        }

        if(identify == 0){
            store.tail->next = temp;
            store.tail = temp;
        }

        dic[hash]->head = store.head;
        dic[hash]->tail = store.tail;
    }
}

bool removeDic(PersonDict *dic, StudName st){

}

//For Closed Hashing
void resize(HigherDict *dic){

}

void initDict2(HigherDict *dic){

}

bool insertDict2(HigherDict *dic, StudName st){

}

bool removeDic2(HigherDict *dic, StudName st){

}

// To Do Functions 
HigherDict *convertToHigherDict(PersonDict dic){

}

Queue *removeInactiveStudents(PersonDict D){

}

char* getProgram(PersonDict dic, int key, char *program){

}