/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Thread, der auf ein Ereignis warten kann.                             */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__
#include"meeting/waitingroom.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Customer :Customer (void* tos)
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
   Waitingroom *wroom;
    Customer (const Customer &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */        
public:
    Customer (void* tos):Entrant(tos){};
    void waiting_in (Waitingroom *w){wroom = w;};
    Waitingroom* waiting_in (){return wroom;};
};

#endif
