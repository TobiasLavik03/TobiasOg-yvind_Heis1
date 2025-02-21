#include "Kø.h"

void legg_til_etasje_i_kø(Kø *aKø, etasje aEtasje){
    aKø->lengde++;
    aKø->liste = (etasje*)realloc(aKø->liste, aKø->lengde * sizeof(etasje)); //finner plass i minnet med plass til ant bytes fra der aKø->liste peker + ant etasjer ganget med etasjestørrelsen
    aKø->liste[aKø->lengde - 1] = aEtasje;
}; 
