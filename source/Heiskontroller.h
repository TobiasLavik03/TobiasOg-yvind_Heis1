#pragma once
#include "driver/elevio.h"
#include "Kø.h"
#include "heispanel.h"
#include "Etasjepanel.h"

void sett_lys(Kø *aKø, int etasje, int dør_åpen);
void åpne_dør();
void lukke_dør();
void kjører_til_neste_stopp(int etasje, int neste_stopp);
void stopp_heis();
void skru_av_alle_lys();
