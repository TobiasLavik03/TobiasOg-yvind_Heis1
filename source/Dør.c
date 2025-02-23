#include "Dør.h"

void start_nedtelling() {
  time_t start_tid = time(NULL);
  while (time(NULL) - start_tid < 3) {
  };
}

