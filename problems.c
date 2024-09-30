#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 0XA

// PROBLEM 1

/**
 * Enqueue: Insert Sorted base on Expiry Date
 * Hash: Multiply each bit indexes of prodID and the Union value of the multipled and prodID
 *        ex. prodID = 5, 0101 index 1 * 3 = (3 : 0011) then Union 0101 and 0011 : Union value: 7 (0111) 
 * 
 * To Do Functions:
 * Dictionary ExpiredProducts(Dictionary, Date, int key); 
 *      => returns a Random dictionary base on key (hash the key) with the products that is expired base on Date 
 *      => Even if key is returning no elements ( just set the count to 0 to determine empty )
 * 
 */

typedef struct{
    int month, day, year;
}Date;

typedef struct{
    int prodID;
    char prodName[30];
    Date expiry;
    Date production;
}Product;

typedef struct{
    Product *prods; // dynamic
    int front;
    int back;
}Queue;

typedef struct {
    Queue *dict; //dynamic
    int count;
    int max;
}Dictionary;




// PROBLEM 2
/*
    Push:
        Insert at the beginning if unit type is "Cavalry"
        Insert at the end if the Legion has a high count of Archers more than any other unit and is NOT of unit type "Cavalry"
        Else Insert before the first instance of the Legion type "Archers"
*/
typedef struct {
    int legionnaire;
    int centurion;
    int lightTroops;
    int archers;
} Soldiers;

typedef struct node {
    int legionNumber;
    char legionType[20];
    Soldiers soldiers;
}Legion;


typedef struct {
    Legion *elems;
    int count;
}Stack;


// TEST CASE (Display)

// The Legions:
// Legion Number: 7, Legion Type: Cavalry
//   Legionnaire: 1100, Centurion: 55, Light Troops: 250, Archers: 200

// Legion Number: 2, Legion Type: Cavalry
//   Legionnaire: 1200, Centurion: 60, Light Troops: 300, Archers: 150

// Legion Number: 1, Legion Type: Infantry
//   Legionnaire: 1000, Centurion: 50, Light Troops: 200, Archers: 300

// Legion Number: 6, Legion Type: Infantry
//   Legionnaire: 500, Centurion: 20, Light Troops: 80, Archers: 50

// Legion Number: 3, Legion Type: Archers
//   Legionnaire: 800, Centurion: 40, Light Troops: 150, Archers: 80

// Legion Number: 4, Legion Type: Infantry
//   Legionnaire: 700, Centurion: 30, Light Troops: 100, Archers: 900

// Legion Number: 5, Legion Type: Archers
//   Legionnaire: 900, Centurion: 35, Light Troops: 120, Archers: 1100

// Legion Number: 8, Legion Type: Archers
//   Legionnaire: 600, Centurion: 25, Light Troops: 100, Archers: 1200










// PROBLEM 3

/**
 * You have a simple task yet crucial for he success of any trip, you are to plan the entire itinerary of towns to visit. 
 * You are given a list of nearby towns together with the jobs of the top 3 VIPs who reside in that town, the gold within that town, and the distance to that town.
 * 
 * Your clients could either be Noble, Knight, orMerchant. Do note that Noble despise and outright avoid towns with any Bandit or Thief. 
 * While Knight actively seek towns with Bandits or a Thief and have no Guards around. Merchant on the other hand prefer to go to 
 * towns whose gold count is within the merchant's budget.
 */

/**
 * TODO
 * enqueue: Insert Sorted the Initial Populate(If u want something challenging)
 * 
 * Below are the functions
 * // Function for Nobles. Delete Towns with...
    void deleteCriminalTowns() {
    }

    // Function for Knights. Delete Towns that do not have... but have...
    void HuntCriminals() {

    }

    // Function for Merchants.
    void deleteHighGoldTowns() {

    }

    // Function to sort the list based on distance
    void sortTownsByDistance() {

    }
 */
typedef struct {
    char job[50];
} Person;

typedef struct node {
    char name[50];
    int gold;
    Person VIP[3];
    char distance[10];
} Town;

typedef struct {
    Town elems[MAX]; // #define MAX 0XA
    int front;
    int rear;
} Queue;

// Just change the variables to Queue
int main(){ 
    
    printf("Prepare itinerary for? (Noble, Knight, Merchant): ");
    scanf("%s", input);

    for (int i = 0; input[i]; i++) {
        input[i] = tolower(input[i]);
    }

    if (strcmp(input, "noble") == 0) {
        printf("\nYour Travel Plans, m'lord...\n\n");
        deleteCriminalTowns(&head);
        printTownNames(head);
    } else if (strcmp(input, "knight") == 0) {
        printf("\nCriminals found here good sir...\n\n");
        HuntCriminals(&head);
        printTownNames(head);
    } else if (strcmp(input, "merchant") == 0) {
        printf("\nOoooh Investments...\n\n");
        int budget;
        printf("Your gold:");
        scanf("%d", &budget);
        deleteHighGoldTowns(&head, budget);
        printTownNames(head);
    } else {
        printf("Invalid role entered.\n");
        head = NULL;
    }
}

// Initial Populate of Queue:

// Your Destinations: Town1-> Town2-> Town3-> Town4-> Town5-> Town6-> Town7-> Town8-> Town9-> Town10-> END
// Final Itinerary:
// Town: Town1, Gold: 100, Distance: 30km
//   VIP 1 Job: Thief
//   VIP 2 Job: Merchant
//   VIP 3 Job: Guard
// Town: Town2, Gold: 200, Distance: 20km
//   VIP 1 Job: Farmer
//   VIP 2 Job: Trader
//   VIP 3 Job: Bandit
// Town: Town3, Gold: 300, Distance: 10km
//   VIP 1 Job: Fishmonger
//   VIP 2 Job: Captain
//   VIP 3 Job: Guard
// Town: Town4, Gold: 150, Distance: 15km
//   VIP 1 Job: Blacksmith
//   VIP 2 Job: Adventurer
//   VIP 3 Job: Wizard
// Town: Town5, Gold: 250, Distance: 25km
//   VIP 1 Job: Bandit
//   VIP 2 Job: Farmer
//   VIP 3 Job: Guard
// Town: Town6, Gold: 350, Distance: 35km
//   VIP 1 Job: Bandit
//   VIP 2 Job: Miner
//   VIP 3 Job: Thief
// Town: Town7, Gold: 180, Distance: 18km
//   VIP 1 Job: Guard
//   VIP 2 Job: Trader
//   VIP 3 Job: Guard
// Town: Town8, Gold: 220, Distance: 22km
//   VIP 1 Job: Thief
//   VIP 2 Job: Miner
//   VIP 3 Job: Farmer
// Town: Town9, Gold: 270, Distance: 27km
//   VIP 1 Job: Blacksmith
//   VIP 2 Job: Miner
//   VIP 3 Job: Bandit
// Town: Town10, Gold: 320, Distance: 32km
//   VIP 1 Job: Trader
//   VIP 2 Job: Miner
//   VIP 3 Job: Guard





// TEST CASES

// Sample Output 1

// Prepare itinerary for? (Noble, Knight, Merchant): Noble

// Your Travel Plans, m'lord...

// Your Destinations: Town3-> Town4-> Town7-> Town10-> END
// Final Itinerary:
// Town: Town3, Gold: 300, Distance: 10km
//   VIP 1 Job: Fishmonger
//   VIP 2 Job: Captain
//   VIP 3 Job: Guard
// Town: Town4, Gold: 150, Distance: 15km
//   VIP 1 Job: Blacksmith
//   VIP 2 Job: Adventurer
//   VIP 3 Job: Wizard
// Town: Town7, Gold: 180, Distance: 18km
//   VIP 1 Job: Guard
//   VIP 2 Job: Trader
//   VIP 3 Job: Guard
// Town: Town10, Gold: 320, Distance: 32km
//   VIP 1 Job: Trader
//   VIP 2 Job: Miner
//   VIP 3 Job: Guard



// Sample Output 2

// Prepare itinerary for? (Noble, Knight, Merchant): Knight

// Criminals found here good sir...

// Your Destinations: Town2-> Town6-> Town8-> Town9-> END
// Final Itinerary:
// Town: Town2, Gold: 200, Distance: 20km
//   VIP 1 Job: Farmer
//   VIP 2 Job: Trader
//   VIP 3 Job: Bandit
// Town: Town8, Gold: 220, Distance: 22km
//   VIP 1 Job: Thief
//   VIP 2 Job: Miner
//   VIP 3 Job: Farmer
// Town: Town9, Gold: 270, Distance: 27km
//   VIP 1 Job: Blacksmith
//   VIP 2 Job: Miner
//   VIP 3 Job: Bandit
// Town: Town6, Gold: 350, Distance: 35km
//   VIP 1 Job: Bandit
//   VIP 2 Job: Miner
//   VIP 3 Job: Thief



// Sample Output 3

// Prepare itinerary for? (Noble, Knight, Merchant): Merchant

// Ooooh Investments...

// Your gold:250
// Your Destinations: Town1-> Town2-> Town4-> Town5-> Town7-> Town8-> END
// Final Itinerary:
// Town: Town4, Gold: 150, Distance: 15km
//   VIP 1 Job: Blacksmith
//   VIP 2 Job: Adventurer
//   VIP 3 Job: Wizard
// Town: Town7, Gold: 180, Distance: 18km
//   VIP 1 Job: Guard
//   VIP 2 Job: Trader
//   VIP 3 Job: Guard
// Town: Town2, Gold: 200, Distance: 20km
//   VIP 1 Job: Farmer
//   VIP 2 Job: Trader
//   VIP 3 Job: Bandit
// Town: Town8, Gold: 220, Distance: 22km
//   VIP 1 Job: Thief
//   VIP 2 Job: Miner
//   VIP 3 Job: Farmer
// Town: Town5, Gold: 250, Distance: 25km
//   VIP 1 Job: Bandit
//   VIP 2 Job: Farmer
//   VIP 3 Job: Guard
// Town: Town1, Gold: 100, Distance: 30km
//   VIP 1 Job: Thief
//   VIP 2 Job: Merchant
//   VIP 3 Job: Guard


// SAMPLE OUTPUT 4

// Prepare itinerary for? (Noble, Knight, Merchant): MerCHANT

// Ooooh Investments...

// Your gold:320
// Your Destinations: Town1-> Town2-> Town3-> Town4-> Town5-> Town7-> Town8-> Town9-> Town10-> END
// Final Itinerary:
// Town: Town3, Gold: 300, Distance: 10km
//   VIP 1 Job: Fishmonger
//   VIP 2 Job: Captain
//   VIP 3 Job: Guard
// Town: Town4, Gold: 150, Distance: 15km
//   VIP 1 Job: Blacksmith
//   VIP 2 Job: Adventurer
//   VIP 3 Job: Wizard
// Town: Town7, Gold: 180, Distance: 18km
//   VIP 1 Job: Guard
//   VIP 2 Job: Trader
//   VIP 3 Job: Guard
// Town: Town2, Gold: 200, Distance: 20km
//   VIP 1 Job: Farmer
//   VIP 2 Job: Trader
//   VIP 3 Job: Bandit
// Town: Town8, Gold: 220, Distance: 22km
//   VIP 1 Job: Thief
//   VIP 2 Job: Miner
//   VIP 3 Job: Farmer
// Town: Town5, Gold: 250, Distance: 25km
//   VIP 1 Job: Bandit
//   VIP 2 Job: Farmer
//   VIP 3 Job: Guard
// Town: Town9, Gold: 270, Distance: 27km
//   VIP 1 Job: Blacksmith
//   VIP 2 Job: Miner
//   VIP 3 Job: Bandit
// Town: Town1, Gold: 100, Distance: 30km
//   VIP 1 Job: Thief
//   VIP 2 Job: Merchant
//   VIP 3 Job: Guard
// Town: Town10, Gold: 320, Distance: 32km
//   VIP 1 Job: Trader
//   VIP 2 Job: Miner
//   VIP 3 Job: Guard