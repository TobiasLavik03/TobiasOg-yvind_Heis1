#include "Heiskontroller.h"

void go_to_default() {
    // kjør til 2 etasje
    // dørene er lukket
};


void kjører_til_neste_stopp(int etasje, int neste_stopp) {
    // dersom neste_stopp = -1  er køen tom, og heisen skal stå i ro. 
    if (neste_stopp == -1) {
        elevio_motorDirection(DIRN_STOP);
    }

    if (neste_stopp > etasje) {
        elevio_motorDirection(DIRN_UP);
    }

    if (neste_stopp < etasje) {
        elevio_motorDirection(DIRN_DOWN);
    }

    if (neste_stopp == etasje) {
        elevio_motorDirection(DIRN_STOP);
    }
}