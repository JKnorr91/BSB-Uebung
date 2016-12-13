/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            E N T R A N T                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine Koroutine, die vom Scheduler verwaltet wird.                         */
/*****************************************************************************/

#ifndef __entrant_include__
#define __entrant_include__

#include "object/chain.h"
#include "thread/coroutine.h"

        
class Entrant : public Chain, public Coroutine
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
      Entrant (const Entrant &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */
public:
      Entrant (void* tos) : Coroutine(tos) {};
 };

#endif
