/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "meeting/semaphore.h"


Semaphore::Semaphore (int c){
    res = c;
}

Semaphore::~Semaphore(){
    Customer *c = (Customer*) dequeue();
    while(c){
        organizer.wakeup(*c);
        c =  (Customer*) dequeue();
    }
}

void Semaphore::p () {
    if (res > 0){
        res--;      //Anz Ressourcen verringern
    }else{
        Customer *c = (Customer*) organizer.active();
        enqueue(c);
        organizer.block(*c,*this);
    }
}

void Semaphore::v (){
    Customer *c = (Customer*) dequeue();
    if (c){
        organizer.wakeup(*c);
    }else{
        res++;
    }

}

void Semaphore::remove (Customer* customer){
    Waitingroom::remove(customer);
}