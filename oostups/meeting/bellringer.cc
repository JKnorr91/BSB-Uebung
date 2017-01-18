/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Queue, die der Gloeckner verwaltet.        */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include"meeting/bellringer.h"

Bellringer::Bellringer() {
    tickstep = 1;
    ticks_to_go = 1;
}

void Bellringer::checkOptimized() {


    if(--ticks_to_go > 0) {
        return;
    }


    Chain* current = first();
    while(current) {

        Bell* currentBell = (Bell*) current;

        for(int i = 0; i < tickstep; i++) {
            currentBell->tick();
        }

        if(currentBell->run_down()) {
            currentBell->ring();
        }

        tickstep = currentBell->wait() < tickstep || tickstep == -1 ? currentBell->wait() : tickstep;

        current = current->next;
    }
    ticks_to_go = tickstep;
}

void Bellringer::checkSimple() {
    Chain* current = first();
    while(current) {

        Bell* currentBell = (Bell*) current;
        currentBell->tick();

        if(currentBell->run_down()) {
            currentBell->ring();
        }

        current = current->next;
    }
}

void Bellringer::check() {
    checkSimple();
}


void Bellringer::job (Bell *bell, int ticks) {
    bell->wait(ticks);
    enqueue(bell);

    int tickstep_before = tickstep;
    tickstep = ticks < tickstep || tickstep == -1 ? ticks : tickstep;

    ticks_to_go = ticks_to_go - (tickstep_before - tickstep);
}


void Bellringer::cancel (Bell *bell) {
    bell->wait(0);
    remove(bell);
}