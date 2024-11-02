#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// MIN HEAP

typedef struct{
    int hr, min, sec;
}Time;

typedef struct {
    int priority;
    char lane[20];
    char direction[20];
    Time time;
}Traffic;

typedef struct{
    Traffic elems[20];
    int last;
}PQ;

Time createTime(int hr, int min);
Time findTotalTime(PQ *p);
Traffic createTraffic(int priority, char *lane, char *direction, Time time);
bool insertPQ(PQ *p, Traffic f);
bool deletePQ(PQ *p);
void insertToFile(Traffic *f);
void readFile();
void displayTraf(Traffic f);

int main(){

    Traffic traf[8] = {
        {2, "div", "right", {45, 21, 124}},
        {8, "div", "straight", {15, 64, 315}},
        {3, "main", "straight", {25, 64, 123}},
        {6, "div", "left", {20, 21, 123}},
        {5, "main", "right", {50, 41, 64}},
        {1, "main", "left", {30, 42, 1}},
        {4, "div", "pedestrian", {35, 643, 2}},
        {7, "main", "pedestrian", {40, 21, 34}}
    };

    insertToFile(traf);
    printf("%-20s%-20s%-20s%-20s\n", "Priority", "Lane", "Path", "Time(s)");
    readFile();

    PQ p;
    p.last = 0;
    
    FILE *fp;
    fp = fopen("traffic.dat", "rb");

    if(fp != NULL){
        Traffic x;
        while(fread(&x, sizeof(Traffic), 1, fp)){
            insertPQ(&p, x);
        }
    }

    fclose(fp);

    printf("\n==============\n");
    for(int i = 0; i < p.last; i++){
        displayTraf(p.elems[i]);
    }

    Time t = findTotalTime(&p);
    printf("\n\nTotal time to MAIN PEDESTRIAN: %02d:%02d:%02d\n\n", t.hr, t.min,t.sec);

    printf("\n==============\n");
    for(int i = 0; i < p.last; i++){
        displayTraf(p.elems[i]);
    }
}

// Time createTime(int hr, int min){
//     Time x = {hr / 12, min / 60};
//     return x;
// }

// Traffic createTraffic(int priority, char *lane, char *direction, Time time){
//     Traffic s;
//     strcpy(s.direction, direction);
//     strcpy(s.lane, lane);
//     s.priority = priority;
//     s.time = time;

//     return s;
// }

Time findTotalTime(PQ *p){

    Time t = {0, 0, 0};
    int i = 0;

    while(p->last != 0 && (strcmp(p->elems[0].lane, "main")) != 0 || (strcmp(p->elems[0].direction, "pedestrian") != 0)){
        t.hr += p->elems[0].time.hr;
        t.min += p->elems[0].time.min;
        t.sec += p->elems[0].time.sec;
        deletePQ(p);
    }

    return t;
}

bool insertPQ(PQ *p, Traffic f){

    int i;
    for(i = p->last; i != 0 && p->elems[(i - 1) / 2].priority > f.priority; i = (i - 1) / 2){
        p->elems[i] = p->elems[(i - 1) / 2];
    }
    p->elems[i] = f;
    p->last++;

    return true;
}

bool deletePQ(PQ *p){

    int i;
    p->last--;

    for(i = 0; i <= p->last && 
        p->elems[p->last].priority > p->elems[(i * 2) + 1].priority || 
        p->elems[p->last].priority > p->elems[(i * 2) + 2].priority ;
    ){
        int left = (i * 2) + 1;
        int right = (i * 2) + 2;

        if(left <= p->last || right <= p->last){
            if(p->elems[left].priority > p->elems[right].priority && right <= p->last){
                p->elems[i] = p->elems[right];
                i = (i * 2) + 2; 
            }else{
                p->elems[i] = p->elems[left];
                i = (i * 2) + 1; 
            }
        }else{
            break;
        }
    }
    p->elems[i] = p->elems[p->last];

    return true;
}

void insertToFile(Traffic *f){

    FILE *fp;

    fp = fopen("traffic.dat", "wb");

    if(fp != NULL){
        fwrite(f, sizeof(Traffic), (sizeof(Traffic) * 8) / sizeof(Traffic), fp);
    }

    fclose(fp);
}

void displayTraf(Traffic f){
    printf("%-20d", f.priority);
    printf("%-20s", f.lane);
    printf("%-20s", f.direction);
    printf("%02d:%02d:%02d", f.time.hr % 24, f.time.min % 60, f.time.sec % 60);
    printf("\n");
}

void readFile(){
    FILE *fp;

    fp = fopen("traffic.dat", "rb");

    if(fp != NULL){
        Traffic f;
        while(fread(&f, sizeof(Traffic), 1, fp)){
            displayTraf(f);
        }
    }

    fclose(fp);

}