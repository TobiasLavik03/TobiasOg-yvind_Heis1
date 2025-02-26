#include "Dør.h"
#include "Heis_tilstand.h"
#include "Heiskontroller.h"
#include "heispanel.h"
#include "Kø.h"
#include "Etasjepanel.h"
#include "driver/elevio.h"
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int main() {
    
  elevio_init();

  Kø aKø = {NULL, 0};   // initaliserer en tom kø

  
  printf("=== Example Program ===\n");
  printf("Press the stop button on the elevator panel to exit\n");


  while (1) {
    heispanel_etasjetrykk(&aKø);
    etasje_tilstand = elevio_floorSensor();

    // setter sist_etasje til etasjen heisen er/var sist i. For å komme unna etasje_tilstand = -1
    if (etasje_tilstand != -1) {
      sist_etasje = etasje_tilstand;
    } 
    
    neste_stopp = finn_neste_stopp(&aKø);

    kjører_til_neste_stopp(sist_etasje, neste_stopp);

    printf("etasje: %d. Neste stopp: %d\n", sist_etasje, neste_stopp);


    nanosleep(&(struct timespec){0, 20 * 1000 * 1000}, NULL);
  }

  return 0;
}
