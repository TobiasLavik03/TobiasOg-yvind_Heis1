#include "Kø.h"

void legg_til_etasje_i_kø(Kø *aKø, Etasje aEtasje){
    aKø->lengde++;
    aKø->liste = (Etasje*)realloc(aKø->liste, aKø->lengde * sizeof(Etasje)); //finner plass i minnet med plass til ant bytes fra der aKø->liste peker + ant etasjer ganget med etasjestørrelsen
    aKø->liste[aKø->lengde - 1] = aEtasje;
}; 

void fjern_etasjer_fra_kø(Kø *aKø, int aEtasje){
    
};