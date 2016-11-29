/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          S C H E D U L E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Schedulers.                                           */
/*****************************************************************************/

#ifndef __schedule_include__
#define __schedule_include__

#include "thread/dispatch.h"
/* Hier muesst ihr selbst Code vervollstaendigen */ 
        
class Scheduler 
/* Hier muesst ihr selbst Code vervollstaendigen */         
 {
private:
      Scheduler (const Scheduler &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 
public:

      void ready (Entrant& that);
      void schedule ();
      void exit ();
      void kill (Entrant& that);
      void resume ();
 };

#endif
