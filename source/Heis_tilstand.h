typedef enum {
    Kjører_opp,
    Kjører_ned,
    stoppmodus,
    truffet_bunn,
    truffet_topp,
    står_stille_i_etasje,
    står_stille_ikke_i_etasje
} Heistilstand;

int volatile etasje;

bool er_i_etasje();
