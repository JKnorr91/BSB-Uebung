/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#ifndef __Semaphore_include__
#define __Semaphore_include__
#include "meeting/waitingroom.h"
#include "syscall/guarded_organizer.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Semaphore : public Waitingroom
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    int res;
    Semaphore (const Semaphore &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */
public:
    ~Semaphore();
    Semaphore (int c);
    void p (); 
    void v ();
    void wait (){p();};
    void signal (){v();};         
 };

#endif
