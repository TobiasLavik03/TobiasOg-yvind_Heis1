#include "Kø.h"

void oppdater_neste_stopp(Kø *aKø) {
    // logikk for å finne neste stopp, ser på avstand til etasje, og retning på ønsket
}
void tøm_kø(Kø *aKø) {
    free(aKø->liste);
    aKø->liste = NULL; //hindrer dangling pointers
    aKø->lengde=0;
}
void legg_til_etasje_i_kø(Kø *aKø, Etasje aEtasje){
    aKø->lengde++;
    aKø->liste = (Etasje*)realloc(aKø->liste, aKø->lengde * sizeof(Etasje)); //finner plass i minnet med plass til ant bytes fra der aKø->liste peker + ant etasjer ganget med etasjestørrelsen. Hvis det er plass der listen allerede peker endres ingenting!
    aKø->liste[aKø->lengde - 1] = aEtasje; //Legger til etasje som siste element
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
