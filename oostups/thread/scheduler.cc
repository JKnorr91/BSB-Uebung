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
    Entrant* currentEntrant = (Entrant*) queue.dequeue();
    if(currentEntrant) {
        dispatch(*currentEntrant);
    }
    else {
        debug.out(0,0,"Scheduler::exit null pointer");
        cpu.halt();
    }
}

void Scheduler::kill (Entrant& that) {
    queue.remove(&that);
}

void Scheduler::resume () {
    Entrant* currentActive = (Entrant*) active();
    ready( *currentActive );
    Entrant* currentEntrant = (Entrant*) queue.dequeue();
    if(currentEntrant) {
        dispatch(*currentEntrant);
    }
    else {
        debug.out(0,0,"Scheduler::resume null pointer");
        cpu.halt();
    }
}