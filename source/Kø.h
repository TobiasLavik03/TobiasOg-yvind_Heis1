#pragma once
#include <stdlib.h>


typedef struct {
  int etasje;
  int retning; // -1 nedover, 1 oppover, 0 ingen retning (for heispanelet)
} Etasje;

typedef struct{
    Etasje* liste;
    int lengde;
} Kø;

extern int neste_stopp;     // extern fordi den deklareres i h fila, men defineres i en annen fil

void legg_til_etasje_i_kø(Kø *aKø, Etasje aEtasje);
int etasje_finnes_i_kø(Kø *aKø, Etasje aEtasje);
void tøm_kø(Kø *aKø);
void oppdater_neste_stopp(Kø *aKø);
void fjern_etasjer_fra_kø(Kø *aKø, int aEtasje);


