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
#include "machine/cpu.h"
#include "device/cgastr.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Semaphore : public Waitingroom
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
    int res;
	int limit;
    Semaphore (const Semaphore &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */
public:
    ~Semaphore();
    Semaphore (int initialValue);
    Semaphore (int initialValue, int limitValue);
    void p (); 
    void v ();
    inline void wait (){p();};
    inline void signal (){v();};
    void remove (Customer* customer);         
 };

#endif
