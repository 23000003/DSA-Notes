#include <stdio.h>
#include <stdbool.h>
#define MAX 20

typedef struct{
    int elems[MAX];
    int count;
}MinHeap;

// n - 1 / 2 find the Parent

bool insertMH(MinHeap *x, int val);
bool deleteMH(MinHeap *x);
 
int main(){
    
    MinHeap x;
    x.count = 0;
    
    insertMH(&x, 12);
    insertMH(&x, 7);
    insertMH(&x, 5);
    insertMH(&x, 15);
    insertMH(&x, 4);
    insertMH(&x, 6);
    
    deleteMH(&x);
    deleteMH(&x);
    deleteMH(&x);
    for(int i = 0; i < x.count; i++){
        printf("%d ", x.elems[i]);
    }
    
    return 0;
}

bool insertMH(MinHeap *x, int val){ // Refactor this
    
    // int parent = (x->count - 1) / 2;
    
    // int test = x->count;
    // x->elems[x->count] = val;
    // while(x->elems[parent] > val){
    //     x->elems[test] = x->elems[parent];
    //     x->elems[parent] = val;
    //     parent = (parent - 1) / 2;
    //     test = (test - 1) / 2;
    // }
    
    // x->count++;
    
    int i;
    for(i = x->count; i != 0 && x->elems[(i - 1) / 2] > val; i = (i - 1) / 2){
        x->elems[i] = x->elems[(i - 1) / 2];
    }
    x->elems[i] = val;
    x->count++;
    return true;
}

bool deleteMH(MinHeap *x){
    
    x->count--;
    int i;
    for(i = 0; x->elems[x->count] > x->elems[i * 2 + 1] && x->elems[x->count] > x->elems[i * 2 + 2] && i <= x->count; ){
        if((i * 2 + 2) <= x->count || (i * 2 + 1) <= x->count)
        {
            if (x->elems[i * 2 + 1] >= x->elems[i * 2 + 2] && (i * 2 + 2) <= x->count){
                x->elems[i] = x->elems[i * 2 + 2];
                i = i * 2 + 2;
            } else {
                x->elems[i] = x->elems[i * 2 + 1];
                i = i * 2 + 1;
            }
        }else{
            break;
        }
    }
    printf("==>>%d\n", i);
    x->elems[i] = x->elems[x->count];

    return true;
}















