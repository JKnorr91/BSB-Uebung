/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Semaphor.                                   */
/*****************************************************************************/

#ifndef __Guarded_Semaphore_include__
#define __Guarded_Semaphore_include__

#include "meeting/semaphore.h"

        
class Guarded_Semaphore : public Semaphore
 {
private:
    Guarded_Semaphore (const Guarded_Semaphore &copy); // Verhindere Kopieren
public:
    Guarded_Semaphore (int c);
    Guarded_Semaphore (int initialValue, int limitValue);
    void p();
    void v();
    void wait();
    void signal();
 };
extern Guarded_Semaphore cgasem;

#endif
