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

  Kø aKø;
  aKø.lengde = 0;  

  
  printf("=== Example Program ===\n");
  printf("Press the stop button on the elevator panel to exit\n");


  while (1) {

    heispanel_etasjetrykk(&aKø);

    etasje = elevio_floorSensor();

    


    nanosleep(&(struct timespec){0, 20 * 1000 * 1000}, NULL);
  }

  return 0;
}
