#ifndef FILTER_QUEUE
#define FILTER_QUEUE

#define MAX 10

typedef struct {
    char fname[30];
    char lname[30];
} Name;

typedef struct {
    Name elems[MAX];
    int front;
    int rear;
} NQueue;

void initNQueue(NQueue *nq);
bool isEmpty(NQueue nq);
bool isFull(NQueue nq);
void displayQueue(NQueue nq);
int countQueue(NQueue q);
bool enqueue(NQueue *nq, Name n);
bool dequeue(NQueue *nq);
Name createName(char fname[], char lname[]);
Name front(NQueue nq);

/*Removes the names that matches the filterString to the lastname. 
  Returns the removed names. Use the concept of adding a sentinel
  at the end indicating the last item in list as empty strings for
  fname and lname. If there are no names that will match then the
  function should return the sentinel.*/
Name *filterNames(NQueue *nq, char *filterString);

/*Insert soreted base on lastname. Rember to use the property 
  of the queue but without using the functions (enqueue, dequeue, front)*/
bool insertSorted(NQueue *nq, Name n);


#endif
