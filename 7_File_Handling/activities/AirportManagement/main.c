#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flight.h"

// MINHEAP

int main(){

    POT h;
    h.last = 0;

    insertToPOT(&h, createFlight(3003, createFlightDetails("CebuPacific", "GES", createSchedule(3, 30, 0))));
    insertToPOT(&h, createFlight(3004, createFlightDetails("AirAsia", "ZAM", createSchedule(3, 30, 0))));
    
    insertToPOT(&h, createFlight(4001, createFlightDetails("Philippine Airlines", "BNT", createSchedule(4, 15, 0))));
    insertToPOT(&h, createFlight(4004, createFlightDetails("Philippine Airlines", "HIL", createSchedule(4, 15, 0))));

    insertToPOT(&h, createFlight(1001, createFlightDetails("CebuPacific", "NAIA", createSchedule(1, 15, 30))));
    insertToPOT(&h, createFlight(1002, createFlightDetails("AirAsia", "CRK", createSchedule(1, 15, 30))));

    insertToPOT(&h, createFlight(5001, createFlightDetails("CebuPacific", "ALT", createSchedule(5, 0, 0))));
    insertToPOT(&h, createFlight(5002, createFlightDetails("AirAsia", "AMR", createSchedule(5, 0, 0))));

    insertToPOT(&h, createFlight(1003, createFlightDetails("Philippine Airlines", "DVO", createSchedule(1, 15, 30))));
    insertToPOT(&h, createFlight(1004, createFlightDetails("CebuPacific", "ILO", createSchedule(1, 15, 30))));
    
    insertToPOT(&h, createFlight(2001, createFlightDetails("AirAsia", "PAG", createSchedule(2, 0, 0))));
    insertToPOT(&h, createFlight(4002, createFlightDetails("CebuPacific", "BUL", createSchedule(4, 15, 0))));
    insertToPOT(&h, createFlight(4003, createFlightDetails("AirAsia", "IBA", createSchedule(4, 15, 0))));
    insertToPOT(&h, createFlight(2002, createFlightDetails("Philippine Airlines", "DGT", createSchedule(2, 0, 0))));
    insertToPOT(&h, createFlight(2003, createFlightDetails("CebuPacific", "SIQ", createSchedule(2, 0, 0))));
    
    insertToPOT(&h, createFlight(3001, createFlightDetails("AirAsia", "BIC", createSchedule(3, 30, 0))));
    
    
    // removePOT(&h);

    for(int i = 0; i < h.last; i++){
        printf("[%d]", i);
        displayFlight(h.flight[i]);
    }
    // InOrder(h, 0);

    /** Transfers to flights file if there are flights ongoing before the passed flightID is its turn**/ 
    insertToFile(h, 3001);

    readFile();

    return 0;
}
