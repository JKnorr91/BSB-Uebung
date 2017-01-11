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
void Semaphore::p () {
    if (res >0){
        res--;      //Anz Ressourcen verringern
    }else{
        
    }
}

void Semaphore::v (){
    Customer *c = (Customer*) dequeue();
    if (c){
        organizer.Organizer::wakeup(c);
    }

}