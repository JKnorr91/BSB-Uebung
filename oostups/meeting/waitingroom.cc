/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "meeting/waitingroom.h"



void Waitingroom::remove (Customer* customer){
    Chain *c = (Chain* ) customer;
    Queue::remove(c);
}