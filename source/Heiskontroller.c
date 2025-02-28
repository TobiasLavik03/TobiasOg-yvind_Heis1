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

    if (neste_stopp == etasje) {
        elevio_motorDirection(DIRN_STOP);
    }

    if (neste_stopp > etasje) {
        elevio_motorDirection(DIRN_UP);
    }

    if (-1 < neste_stopp && neste_stopp < etasje) {
        elevio_motorDirection(DIRN_DOWN);
    }

    
}

void sett_lys(Kø *aKø, int etasje, int dør_åpen){
    printf("%d\n", aKø->lengde);
    for(int i=0; i<aKø->lengde; i++){
        // HEISPANEL_LYS
        if(aKø->liste[i].etasje == 0 && aKø->liste[i].retning == 0){
            elevio_buttonLamp(0, BUTTON_CAB, 1);
        }
        if(aKø->liste[i].etasje == 1 && aKø->liste[i].retning == 0){
            elevio_buttonLamp(1, BUTTON_CAB, 1);
        }
        if(aKø->liste[i].etasje == 2 && aKø->liste[i].retning == 0){
            elevio_buttonLamp(2, BUTTON_CAB, 1);
        }
        if(aKø->liste[i].etasje == 3 && aKø->liste[i].retning == 0){
            elevio_buttonLamp(3, BUTTON_CAB, 1);
        }
        //ETASJEPANELLYS
        if(aKø->liste[i].etasje == 0 && aKø->liste[i].retning == 1){
            elevio_buttonLamp(0, BUTTON_HALL_UP, 1);
        }
        if(aKø->liste[i].etasje == 1 && aKø->liste[i].retning == 1){
            elevio_buttonLamp(1, BUTTON_HALL_UP, 1);
        }
        if(aKø->liste[i].etasje == 2 && aKø->liste[i].retning == 1){
            elevio_buttonLamp(2, BUTTON_HALL_UP, 1);
        }
        if(aKø->liste[i].etasje == 1 && aKø->liste[i].retning == -1){
            elevio_buttonLamp(1, BUTTON_HALL_DOWN, 1);
        }
        if(aKø->liste[i].etasje == 2 && aKø->liste[i].retning == -1){
            elevio_buttonLamp(2, BUTTON_HALL_DOWN, 1);
        }
        if(aKø->liste[i].etasje == 3 && aKø->liste[i].retning == -1){
            elevio_buttonLamp(3, BUTTON_HALL_DOWN, 1);
        }
    }
    
    // ETASJELYS
    elevio_floorIndicator(etasje);

    // OBSTRUKSJONSLYS
    // kalles i Dør.c under start_nedtelling()
};

void skru_av_alle_lys() {

    elevio_buttonLamp(1, BUTTON_HALL_DOWN, 0);
    elevio_buttonLamp(2, BUTTON_HALL_DOWN, 0);
    elevio_buttonLamp(3, BUTTON_HALL_DOWN, 0);

    elevio_buttonLamp(2, BUTTON_HALL_UP, 0);
    elevio_buttonLamp(1, BUTTON_HALL_UP, 0);
    elevio_buttonLamp(0, BUTTON_HALL_UP, 0);
    
    elevio_buttonLamp(3, BUTTON_CAB, 0);
    elevio_buttonLamp(2, BUTTON_CAB, 0);
    elevio_buttonLamp(1, BUTTON_CAB, 0);
    elevio_buttonLamp(0, BUTTON_CAB, 0);

    elevio_doorOpenLamp(0);
}
