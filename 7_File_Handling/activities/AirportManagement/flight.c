#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

Flight createFlight(int flightcode, FlightDetails flightDets){
    Flight x;
    x.flightCode = flightcode;
    x.flightDets = flightDets;
    return x;
}

FlightDetails createFlightDetails(char *aircraft, char *destination, Time schedule){
    FlightDetails x;
    strcpy(x.aircraft, aircraft);
    strcpy(x.destination, destination);
    x.schedule = schedule;
    return x;
}

Time createSchedule(int hr, int min, int sec){
    Time x;
    x.hr = hr % 24;
    x.min = min % 60;
    x.sec = sec % 60;
    return x;
}

int checkTime(Time t1, Time t2) { // ret 1 if t1 is greater
    if (t1.hr > t2.hr) {
        return 1; 
    } else if (t1.hr == t2.hr) {
        if (t1.min > t2.min) {
            return 1; 
        } else if (t1.min == t2.min) {
            if (t1.sec >= t2.sec) {
                return 1;
            }
        }
    }
    return 0;
}

void insertToPOT(POT *p, Flight f){

    int i;
    for(i = p->last; i != 0 && checkTime(p->flight[(i - 1) / 2].flightDets.schedule, f.flightDets.schedule) > 0; i = (i - 1) / 2){
        p->flight[i] = p->flight[(i - 1) / 2];
    }
    p->flight[i] = f;
    p->last++;
}

void InOrder(POT p, int count){
    if(p.last > count){
        InOrder(p, (count * 2) + 1);
        displayFlight(p.flight[count]);
        InOrder(p, (count * 2) + 2);
    }
}


void displayFlight(Flight f){
    printf("===== Flight: %d =====\n", f.flightCode);
    printf("Aircraft: %s\n", f.flightDets.aircraft);
    printf("Destination: %s\n", f.flightDets.destination);
    printf("%02d:%02d:%02d\n", f.flightDets.schedule.hr, f.flightDets.schedule.min, f.flightDets.schedule.sec);
}

void removePOT(POT *p){

    p->last--;
    int i;
    for(i = 0; 
        checkTime(p->flight[p->last].flightDets.schedule, p->flight[i * 2 + 1].flightDets.schedule) > 0 && 
        checkTime(p->flight[p->last].flightDets.schedule, p->flight[i * 2 + 2].flightDets.schedule) > 0 && 
        i <= p->last; 
    ){    
        if((i * 2 + 2) <= p->last || (i * 2 + 1) <= p->last)
        {
            if (checkTime(p->flight[i * 2 + 1].flightDets.schedule, p->flight[i * 2 + 2].flightDets.schedule) > 0 &&
                (i * 2 + 2) <= p->last)
            {
                p->flight[i] = p->flight[i * 2 + 2];
                i = i * 2 + 2;
            } else {
                p->flight[i] = p->flight[i * 2 + 1];
                i = i * 2 + 1;
            }
        }else{
            break;
        }
    }
    p->flight[i] = p->flight[p->last];
}

void insertToFile(POT p, int flightCode){
    FILE *fp;

    fp = fopen("flights.txt", "wb");

    for(int i = 0; i < p.last; i++){
        if(fp != NULL){
            displayFlight(p.flight[i]);
            if(p.flight[i].flightCode != flightCode){
                fwrite(&p.flight[i], sizeof(Flight), 1, fp);
            }else{
                break;
            }
        }
    }

    fclose(fp);

}

void readFile(){
    Flight temp;

    FILE *fp;

    fp = fopen("flights.txt", "rb");
    printf("\n==================\n\n");
    if(fp != NULL){
        while(fread(&temp, sizeof(Flight), 1, fp)){
            displayFlight(temp);
        }
    }

    fclose(fp);

}
