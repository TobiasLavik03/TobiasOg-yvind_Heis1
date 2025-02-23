#pragma once
#include <stdbool.h>
#include <time.h>
#include "Heis_tilstand.h"



void start_nedtelling();

void endre_tilstand_obstruksjon(Heistilstand *heistilstand);        // kalles dersom elevio_obstruction() endres
