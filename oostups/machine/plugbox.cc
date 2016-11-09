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
/* Hier muesst ihr selbst Code vervollstaendigen */ 
Plugbox::Plugbox (){
	int i = 0;
	for (i=1;i<64;i++){
		interrupts[i] = panic;
	}
}


void Plugbox::assign (unsigned int slot, Gate& gate){
	interrupts[slot] = gate;
}

Gate& Plugbox::report (unsigned int slot){
	return interrupts[slot];
}
