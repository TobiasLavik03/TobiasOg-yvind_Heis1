#pragma once
#include <stdbool.h>

typedef enum {
    Kjører_opp,
    Kjører_ned,
    stoppmodus,
    truffet_bunn,
    truffet_topp,
    står_stille_i_etasje,
    står_stille_ikke_i_etasje,
    obstruksjon
} Heistilstand;

extern volatile int etasje_tilstand;
extern volatile int sist_etasje;   
extern volatile int retning;                             // etasjen heisen er i eller forrige etasje dersom heisen er i bevegelse

int er_i_neste_etasje(int etasje_tilstand, int neste_stopp);    // sjekekr om etasje == neste_stopp

void go_to_default();

void endre_tilstand_obstruksjon(Heistilstand *heistilstand);        // kalles dersom elevio_obstruction() endres

void go_to_default();

int etasje_sist_vært_i(int etasje);     

