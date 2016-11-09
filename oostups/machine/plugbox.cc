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
/* Hier muesst ihr selbst Code vervollstaendigen */ 
Plugbox::Plugbox (){}
void Plugbox::assign (unsigned int slot, Gate& gate){}
Gate& Plugbox::report (unsigned int slot){}
