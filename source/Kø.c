#include "Kø.h"

void oppdater_neste_stopp(Kø *aKø) {
    // logikk for å finne neste stopp, ser på avstand til etasje, og retning på ønsket
}
void tøm_kø(Kø *aKø) {
    // tømmer hele køen
}
void legg_til_etasje_i_kø(Kø *aKø, Etasje aEtasje){
    aKø->lengde++;
    aKø->liste = (Etasje*)realloc(aKø->liste, aKø->lengde * sizeof(Etasje)); //finner plass i minnet med plass til ant bytes fra der aKø->liste peker + ant etasjer ganget med etasjestørrelsen
    aKø->liste[aKø->lengde - 1] = aEtasje;
}; 

void fjern_etasjer_fra_kø(Kø *aKø, int aEtasje){
    
};
