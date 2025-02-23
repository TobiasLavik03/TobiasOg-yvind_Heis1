typedef enum {
    Kjører_opp,
    Kjører_ned,
    stoppmodus,
    truffet_bunn,
    truffet_topp,
    står_stille_i_etasje,
    står_stille_ikke_i_etasje,
    obstruksjon
} Heistilstand;

int volatile etasje;

int er_i_etasje();

void go_to_default();

void endre_tilstand_obstruksjon(Heistilstand *heistilstand);        // kalles dersom elevio_obstruction() endres

