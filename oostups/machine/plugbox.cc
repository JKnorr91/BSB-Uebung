/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Behandlungs- */
/* routine fuer jeden Hardware-, Softwareinterrupt und jede Prozessor-       */
/* exception festlegen.                                                      */
/*****************************************************************************/
#include "machine/plugbox.h"
#include "device/panic.h"

Plugbox::Plugbox (){
	int i = 0; // warum beginnt i bei 1?
	for (i = 1; i < SLOT_COUNT; i++){
		interrupts[i] = panic;
	}
}


void Plugbox::assign (unsigned int slot, Gate& gate){
	if (slot >= 0 && slot < SLOT_COUNT) {
		interrupts[slot] = gate;
	}
}

Gate& Plugbox::report (unsigned int slot){
	return interrupts[slot];
}
