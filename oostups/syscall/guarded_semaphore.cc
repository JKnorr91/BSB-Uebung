/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Semaphor.                                   */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "syscall/guarded_semaphore.h"
#include "guard/secure.h"

Guarded_Semaphore::Guarded_Semaphore (int c) :Semaphore(c){

}
void Guarded_Semaphore::p(){
    {Secure section;
   		Semaphore::p();
    }
}
void Guarded_Semaphore::v(){
    {Secure section;
   		Semaphore::v();
    }
}
void Guarded_Semaphore::wait(){
    {Secure section;
   		Semaphore::wait();
    }
}
void Guarded_Semaphore::signal(){
    {Secure section;
   		Semaphore::signal();
    }
}
