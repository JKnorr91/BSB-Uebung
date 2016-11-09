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

#define SLOT_COUNT 64

#include "guard/gate.h"

class Plugbox
 {
private:
	Gate interrupts[SLOT_COUNT];
    Plugbox(const Plugbox &copy); // Verhindere Kopieren
public:
	static const int timer = 32;
	static const int keyboard = 33;
	Plugbox ();
	void assign (unsigned int slot, Gate& gate);
	Gate& report (unsigned int slot);
 };
extern Plugbox plugbox;
#endif
