#include "Heis_tilstand.h"

volatile int etasje_tilstand = 0;   // -1 : heis i bevegelse  | 0 : 1. etasje  | 1 : 2. etasje osv
volatile int sist_etasje = 0;
extern volatile int retning=0;  // -1 : kjører ned  |  0 : står i ro  |  1 : kjører opp


int er_i_neste_etasje(int etasje_tilstand, int neste_stopp) {
    if (etasje_tilstand == neste_stopp) {
        return 1;
    } else {
        return 0;
    }
}

