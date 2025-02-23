#pragma once
#include "Kø.h"
#include <stdbool.h>
#include "Heis_tilstand.h"


typedef struct {
    bool etasje_lys1;
    bool etasje_lys2;
    bool etasje_lys3;
    bool etasje_lys4;
    bool stoppknapp_lys; 
} Heispanel_lys;

Etasje heispanelknapp_trykket();
void endre_tilstand_stoppmodus(Heistilstand *tilstand);


