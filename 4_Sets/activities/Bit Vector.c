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
    
    Set a, b;
    
    printf("===== Set a =====:\n");
    
    if (addElement(&a, 5)){
    	printf("%d\n", a);
	}
    
//	if(addElement(&a, 5)){
//    	printf("%d\n", a);
//	}
    
    if(addElement(&a, 1)){
    	printf("%d\n", a);
	}
	
//	if(removeElement(&a, 2)){
//    	printf("%d\n", a);
//	}
//	
//	if(removeElement(&a, 1)){
//    	printf("%d\n", a);
//	}
	
	displaySet(a);
	
	printf("===== Set b =====:\n");
	if(addElement(&b, 5)){
    	printf("%d\n", b);
	}
	
	if(addElement(&b, 7)){
    	printf("%d\n", b);
	}
	
	displaySet(b);
	
	printf("==== Union Set ====\n");
	displaySet(unionSet(a, b));
	
	printf("==== Intersection Set ====\n");
	displaySet(intersectionSet(a, b));
	
	printf("==== Difference Set of A ====\n");
	displaySet(differenceSet(a, b));
	
	printf("==== Difference Set of B ====\n");
	displaySet(differenceSet(b, a));
	
	printf("==== SymmetricDiff Set ====\n");
	displaySet(symmetricDifferenceSet(a, b));
	
	printf("==== Cardinality of A ====\n");
	printf("%d\n\n", cardinality(a));
	
	printf("==== isElement? ====\n");
	(isElement(a,  5)) ? printf("Is Element\n") : printf("Is not an Element");
    
    return 0;
}
// change bit value to 1 base on the item (determine the value base on bit index)
// 0000 0000 0000 0000
// 15 - 0 => value 
bool addElement(Set *s, int item){
	
	if(item > 16 || item < 0) return false;
	
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
	
	if(item > 16 || item < 0) return false;
	
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
    
    // PRINTS IN BINARY FORMAT
//    for (i = sizeof(s) * 8 - 1; i >= 0; i--) {
//        printf("%d", (s >> i) & 1);
//        if (i % 4 == 0) printf(" ");
//    }
    printf("\n\n");
}

Set unionSet(Set a, Set b){
	return a | b;
}

Set intersectionSet(Set a, Set b){
	return a & b;
}
//ex.
//a 0110 0101
//b 0100 0110
// if return difference of a = 0000 0010   if b = 0010 0001
Set differenceSet(Set a, Set b){
	return a & ~b; // inverts "b" to check using "AND" on "a" if its present or not;
}

Set symmetricDifferenceSet(Set a, Set b){
	return a ^ b;
}

int cardinality(Set a){
	int i, count = 0;
	for (i = 0; a > 0; i++, a = a >> 1){
        if (a & 1){ 
            count++;
        }
    }
    
    return count;
}

bool isElement(Set s, int item){
	
	return (s & (1 << item)) != 0;
}












