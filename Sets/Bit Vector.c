#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

//I'm still a noob :((
typedef short int Set;

bool addElement(Set *s, int item);
bool removeElement(Set *s, int item);
void displaySet(Set s);

Set unionSet(Set a, Set b);
Set intersectionSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDifferenceSet(Set a, Set b); //(A - B) U (B - A)
int cardinality(Set a);
bool isElement(Set s, int item);

int main(){
    
    Set a;
    
    if (addElement(&a, 5)){
    	printf("%d\n", a);
	}
    
	if(addElement(&a, 5)){
    	printf("%d\n", a);
	}
    
    if(addElement(&a, 1)){
    	printf("%d\n", a);
	}
	
	displaySet(a);
	
	if(removeElement(&a, 2)){
    	printf("%d\n", a);
	}
	
	if(removeElement(&a, 1)){
    	printf("%d\n", a);
	}
	
	displaySet(a);
    
    return 0;
}
// change bit value to 1 base on the item (determine the value base on bit index)
// 0000 0000 0000 0000
// 15 - 0 => value 
bool addElement(Set *s, int item){
	Set temp = 1 << item;

	//can be (*s >> item) == 1
	if((*s & temp) != 0){ // check if bit is set (non-zero)
		printf("Value already exists\n");
		return false;
	}
	
	*s |= temp;
	
	return true;
}

bool removeElement(Set *s, int item){
	Set temp = 1 << item;
	
	if((*s & temp) == 0){
		printf("Value doesnt exists\n");
		return false;
	}
	
	*s ^= temp;
}

void displaySet(Set s){
	int i;
	for (i = 0; s > 0; i++, s = s >> 1){ // shifts to right 
        if (s & 1){ // if ex. s = 0000 1001 = 0000 0001 (1) then true
            printf("%d ",i);
        }
    }
    printf("\n");
}

Set unionSet(Set a, Set b){
	
}

Set intersectionSet(Set a, Set b){

}

Set differenceSet(Set a, Set b){
	
}

Set symmetricDifferenceSet(Set a, Set b){
	
}

int cardinality(Set a){
	
}

bool isElement(Set s, int item){
	
}

//#include <stdio.h>      // USE BITWISE OPERATOR
//int main()
//{
//    // a = 5 (00000101 in 8-bit binary), b = 9 (00001001 in
//    // 8-bit binary)
//    unsigned int a = 5, b = 9;
//
//    // The result is 00000001
//    printf("a = %u, b = %u\n", a, b);
//    printf("a&b = %u\n", a & b);
//
//    // The result is 00001101
//    printf("a|b = %u\n", a | b);
//
//    // The result is 00001100
//    printf("a^b = %u\n", a ^ b);
//
//    // The result is 11111111111111111111111111111010
//    // (assuming 32-bit unsigned int)
//    printf("~a = %u\n", a = ~a);
//
//    // The result is 00010010
//    printf("b<<1 = %u\n", b << 1);
//
//    // The result is 00000100
//    printf("b>>1 = %u\n", b >> 1);
//
//    return 0;
//}
//












