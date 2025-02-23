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

  // lite testprogram hvor man lager køen manuelt
  Etasje e1 = {1, 0};
  Etasje e2 = {2, 1};
  Etasje e3 = {3, -1};

  Kø aKø;
  aKø.lengde = 0;
  legg_til_etasje_i_kø(&aKø, e1);
  legg_til_etasje_i_kø(&aKø, e2);
  legg_til_etasje_i_kø(&aKø, e3);


  
  
  int etasje = 0;

  printf("=== Example Program ===\n");
  printf("Press the stop button on the elevator panel to exit\n");

  elevio_motorDirection(DIRN_UP);

  while (1) {

    if (elevio_callButton(2, BUTTON_HALL_UP)) {
      printf("Første etasje oppover\n");
    }

    etasje = elevio_floorSensor();

    if (etasje == 0) {
      elevio_motorDirection(DIRN_UP);
    };

    if (etasje == 3) {
      elevio_motorDirection(DIRN_DOWN);
    } ;


    nanosleep(&(struct timespec){0, 20 * 1000 * 1000}, NULL);
  }

  return 0;
}
