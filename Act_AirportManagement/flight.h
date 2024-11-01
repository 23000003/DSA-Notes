#ifndef FLIGHT_H
#define FLIGHT_H

typedef struct{
    int hr, min, sec;
}Time;

typedef struct {
    char aircraft[20];
    char destination[50];
    Time schedule;
}FlightDetails;

typedef struct{
    int flightCode;
    FlightDetails flightDets;
} Flight;

typedef struct {
    Flight flight[20];
    int last;
}POT;

Flight createFlight(int flightcode, FlightDetails flightDets);
FlightDetails createFlightDetails(char *aircraft, char *destination, Time schedule);
Time createSchedule(int hr, int min, int sec);

int checkTime(Time t1, Time t2);

void insertToPOT(POT *p, Flight f);
void removePOT(POT *p);
void displayFlight(Flight f);
void InOrder(POT p, int count);

void insertToFile(POT p, int flightCode);
void readFile();


#endif