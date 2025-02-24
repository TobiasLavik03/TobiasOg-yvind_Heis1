#include "Kø.h"
#include<stdlib.h>

void oppdater_neste_stopp(Kø *aKø) {
    // logikk for å finne neste stopp, ser på avstand til etasje, og retning på ønsket
}

// tømmer hele køen
void tøm_kø(Kø* k) {
    if (k->liste != NULL) {
        free(k->liste);         // Frigjør minnet som er allokert til listen
        k->liste = NULL;        // Nullstiller pekeren
    }
    k->lengde = 0;              // Nullstiller lengden
>>>>>>> e66c6a82aee7679508e1f8fc0d99fc335035772a
}


void legg_til_etasje_i_kø(Kø *aKø, Etasje aEtasje){
    aKø->lengde++;

    aKø->liste = (Etasje*) realloc(aKø->liste, aKø->lengde * sizeof(Etasje)); //finner plass i minnet med plass til ant bytes fra der aKø->liste peker + ant etasjer ganget med etasjestørrelsen
    aKø->liste[aKø->lengde - 1] = aEtasje;

    // må legge til et "filter" slik at ikke samme etasje legges til flere ganger

>>>>>>> e66c6a82aee7679508e1f8fc0d99fc335035772a
}; 


void fjern_etasjer_fra_kø(Kø *aKø, int aEtasje){
    Etasje* ny_liste = (Etasje*)malloc(aKø->lengde * sizeof(Etasje)); //lager plass til en ny liste. Her vil vi legge alle etasjene som ikke er aEtasje
    int ny_lengde = 0;
    for (int i = 0; i < aKø->lengde; i++){
        if (aKø->liste[i].etasje != aEtasje){ //går gjennom listen og legger de etasjene som IKKE er i aEtasje inn i den nye listen
            ny_liste[ny_lengde] = aKø->liste[i];
            ny_lengde++;
        }
    }
    free(aKø->liste); //frigjør det gamle minnet vi ikke lenger har behov for
    aKø->liste = (Etasje*)realloc(ny_liste, ny_lengde * sizeof(Etasje)); //reallokerer minnet slik at aKø->liste peker til et nytt sted (sannsynligvis samme sted som ny_liste)
    aKø->lengde = ny_lengde;
};
