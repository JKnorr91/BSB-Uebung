/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/


#include "machine/cpu.h"
#include "user/debug.h"
#include "thread/scheduler.h"
#include "guard/guard.h"

void Scheduler::ready (Entrant& that) {
    queue.enqueue(&that);
}

void Scheduler::schedule () {
    Entrant* currentEntrant = (Entrant*) queue.dequeue();
    if(currentEntrant) {
        go(*currentEntrant);
    }
    else {
        debug.out(0,0,"Scheduler::schedule null pointer");
        cpu.halt();
    }
}

void Scheduler::exit () {
    idleDispatch();
/*    if(currentEntrant) {
        dispatch(*currentEntrant);
    }
    else {
        debug.out(0,0,"Scheduler::exit null pointer");
        cpu.halt();
    }*/
}

void Scheduler::idleDispatch() {
	Entrant* currentEntrant = 0;
	guard.leave();
	cpu.disable_int();
	while (!(currentEntrant = (Entrant*) queue.dequeue())) {
		cpu.idle();
		cpu.disable_int();
	}
	guard.enter();
	cpu.enable_int();
	dispatch(*currentEntrant);
}

void Scheduler::kill (Entrant& that) {
    queue.remove(&that);
}

void Scheduler::resume () {
	Entrant* currentEntrant = (Entrant*) queue.dequeue();
	if (!currentEntrant) {
		return;
	}
    Entrant* currentActive = (Entrant*) active();
    ready( *currentActive );
    dispatch(*currentEntrant);
}
