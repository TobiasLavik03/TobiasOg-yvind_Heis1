typedef struct{
    int etasje;
    int retning;
} etasje;

typedef struct{
    etasje* liste;
    int lengde;
} Kø;

int neste_stopp;

void legg_til_etasje_i_kø(Kø *aKø, etasje aEtasje);
void fjern_etasjer_fra_kø(Kø &aKø, int aEtasje);
void oppdater_neste_stopp();

