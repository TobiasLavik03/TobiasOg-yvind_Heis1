#include "Heiskontroller.h"

// setter motorpådrag og endrer variabelen retning
void kjører_til_neste_stopp(int etasje, int neste_stopp) { 
    // dersom neste_stopp = -1  er køen tom, og heisen skal stå i ro. 
    if (neste_stopp == -1) {
        elevio_motorDirection(DIRN_STOP);
        retning=0;
    }

    if (neste_stopp == etasje) {
        elevio_motorDirection(DIRN_STOP);
        retning=0;
    }

    if (neste_stopp > etasje) {
        elevio_motorDirection(DIRN_UP);
        retning=1;
    }

    if (-1 < neste_stopp && neste_stopp < etasje) {
        elevio_motorDirection(DIRN_DOWN);
        retning=-1;
    }
}

void sett_lys(Kø *aKø, int etasje, int dør_åpen){
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

 //Kjører til tredje etasje og døren er lukket 
void go_to_default(Kø aKø){
    etasje_tilstand = elevio_floorSensor();
    neste_stopp = 2;

    while(etasje_tilstand!=2){
        if (etasje_tilstand != -1) {
            sist_etasje = etasje_tilstand;
          };
          elevio_floorIndicator(sist_etasje);
          etasje_tilstand = elevio_floorSensor();
    
          kjører_til_neste_stopp(sist_etasje, neste_stopp);
          nanosleep(&(struct timespec){0, 20 * 1000 * 1000}, NULL);
    }
    elevio_floorIndicator(etasje_tilstand);
};