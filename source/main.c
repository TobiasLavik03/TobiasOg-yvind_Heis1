#include "Dør.h"
#include "Heis_tilstand.h"
#include "Heiskontroller.h"
#include "heispanel.h"
#include "Kø.h"
#include "Etasjepanel.h"
#include "driver/elevio.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    
  elevio_init();
  etasje = 0;


  printf("=== Example Program ===\n");
  printf("Press the stop button on the elevator panel to exit\n");

  elevio_motorDirection(DIRN_UP);

  while (1) {
    etasje = elevio_floorSensor();

    if (etasje == 0) {
      elevio_motorDirection(DIRN_UP);
    };

    if (etasje == 3) {
      elevio_motorDirection(DIRN_DOWN);
    } ;

    printf("Etasje: %d \n", etasje);

    nanosleep(&(struct timespec){0, 20 * 1000 * 1000}, NULL);
  }

  return 0;
}
