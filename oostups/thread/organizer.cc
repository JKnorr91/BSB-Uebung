/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Organizer ist ein spezieller Scheduler, der zusaetzlich das Warten    */
/* von Threads (Customer) auf Ereignisse erlaubt.                            */
/*****************************************************************************/


#include "thread/organizer.h"


void Organizer::block(Customer& customer, Waitingroom& waitingroom) {
    waitingroom.enqueue(&customer);
    customer.waiting_in(&waitingroom);
    resume();
}

void Organizer::kill(Customer& that) {
    Waitingroom* waitingroom = that.waiting_in();

    //In der Ready-List
    if(!waitingroom) {
        Scheduler::kill(that);
    }
    else {
        waitingroom->remove(&that);
    }
}

void Organizer::wakeup(Customer& customer) {
    Waitingroom* waitingroom = customer.waiting_in();

    if(waitingroom) { 
        waitingroom->remove(&customer);
        customer.waiting_in(0);
    }

    Scheduler::ready(customer);
}