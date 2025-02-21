typedef struct{
    int etasje;
    int retning;        // -1 nedover, 1 oppover, 0 ingen retning (for heispanelet)
} Etasje;

int neste_stopp;


void legg_til_etasje_i_kø();
void oppdater_neste_stopp();

