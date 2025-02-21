typedef struct {
  int etasje;
  int retning; // -1 nedover, 1 oppover, 0 ingen retning (for heispanelet)
} Etasje;

int neste_stopp;

void legg_til_etasje_i_kø();
void oppdater_neste_stopp();

<<<<<<< HEAD
typedef struct {
  Etasje *liste;
  int lengde;
=======
typedef struct{
    Etasje* liste;
    int lengde;
>>>>>>> 9a31b138ad306493d009e7e1126933c0de87c48b
} Kø;

int neste_stopp;

void legg_til_etasje_i_kø(Kø *aKø, Etasje aEtasje);
<<<<<<< HEAD
void tøm_kø(Kø *aKø, int aEtasje);
void oppdater_neste_stopp(Kø *aKø);
=======
void fjern_etasjer_fra_kø(Kø &aKø, int aEtasje);
void oppdater_neste_stopp();

>>>>>>> 9a31b138ad306493d009e7e1126933c0de87c48b
