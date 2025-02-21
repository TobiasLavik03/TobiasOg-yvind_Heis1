#include "Dør.h"

void start_nedtelling() {
  time_t start_tid = time(NULL);
  while (time(NULL) - start_tid < 3) {
  };
}

void endre_tilstand_obstruksjon(Heistilstand *heistilstand) {
    // endrer tilstanden obstruksjon i heistilstand-enum
};