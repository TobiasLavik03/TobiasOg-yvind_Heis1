#pragma once

typedef struct {
  int etasje;
  int retning; // -1 nedover, 1 oppover, 0 ingen retning (for heispanelet)
} Etasje;

typedef struct{
    Etasje* liste;
    int lengde;
} Kø;

int neste_stopp;

void legg_til_etasje_i_kø(Kø *aKø, Etasje aEtasje);
void tøm_kø(Kø *aKø);
void oppdater_neste_stopp(Kø *aKø);
void fjern_etasjer_fra_kø(Kø *aKø, int aEtasje);


