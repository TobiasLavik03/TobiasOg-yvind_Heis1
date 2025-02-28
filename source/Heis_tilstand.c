#include "Heis_tilstand.h"

volatile int etasje_tilstand = 0;   // -1 : heis i bevegelse  | 0 : 1. etasje  | 1 : 2. etasje
volatile int sist_etasje = 0;


int er_i_neste_etasje(int etasje_tilstand, int neste_stopp) {
    if (etasje_tilstand == neste_stopp) {
        return 1;
    } else {
        return 0;
    }
}

