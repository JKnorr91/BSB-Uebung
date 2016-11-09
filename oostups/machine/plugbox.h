/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Adresse der  */
/* Behandlungsroutine fuer jeden Hardware-, Softwareinterrupt und jede       */
/* Prozessorexception festlegen.                                             */
/*****************************************************************************/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"

class Plugbox
 {
private:
	Gate interrupts[64];
    Plugbox(const Plugbox &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 
public:
	const int timer = 32;
	const int keyboard = 33;
	Plugbox ();
	void assign (unsigned int slot, Gate& gate);
	Gate& report (unsigned int slot);
 };
extern Plugbox plugbox;
#endif
