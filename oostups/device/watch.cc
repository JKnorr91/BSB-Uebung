/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#include "device/watch.h"
#include "machine/plugbox.h"

void Watch::windup() {
    plugbox.assign(Plugbox::timer, *this);
	pic.allow(PIC::timer);
}

bool Watch::prologue (){
	return true;
}

void Watch::epilogue (){
	bellringer.check();
	organizer.Scheduler::resume();
}
