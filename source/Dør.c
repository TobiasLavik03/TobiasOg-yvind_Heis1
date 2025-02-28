#include "Dør.h"

volatile int dør_åpen = 0;


// PROBLEM: hele programmet går i en "pause" i denne while løkka, som gjør at man ikke kan
// legge til nye etasjer i køen osv...
void start_nedtelling() {
  time_t start_tid = time(NULL);
  while (time(NULL) - start_tid < 3) {
    dør_åpen = 1;
    printf("Dør åpen: %d\n", dør_åpen);
  };

  dør_åpen = 0;
}

