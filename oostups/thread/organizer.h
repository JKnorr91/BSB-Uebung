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

#ifndef __organizer_include__
#define __organizer_include__
#include "thread/scheduler.h"
#include "thread/customer.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
class Organizer:public Scheduler
/* Hier muesst ihr selbst Code vervollstaendigen */ 
{
private:
    Organizer(const Organizer &copy); // Verhindere Kopieren
public:
    Organizer() {};
    void block (Customer& customer, Waitingroom& waitingroom);
    void wakeup (Customer& customer);
    void kill (Customer& that);
/* Hier muesst ihr selbst Code vervollstaendigen */ 
};

#endif
