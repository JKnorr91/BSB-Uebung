/* $Id: queue.cc 956 2008-10-19 22:24:23Z hsc $ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Q U E U E                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung einer einfach verketteten Liste von Chain Objekten.       */
/* enqueue fuegt ein neues Element an das Ende der Liste an.                 */
/* dequeue entfernt das erste und remove das angegebene Element der Liste.   */
/* Initial ist die Liste leer.                                               */
/*                                                                           */
/* Die Implementierung ist etwas trickreich (siehe Vorlesung).               */
/* tail verweist naemlich nicht, wie oft ueblich, auf das letzte Element der */
/* Liste, sondern auf den next Zeiger des letzten Elements, bzw., solange    */
/* die Liste noch leer ist, auf den head Zeiger der Liste. Dadurch muss beim */
/* Anfuegen eines Elements an die Liste nicht ueberprueft werden, ob bereits */
/* Elemente in ihr enthalten sind. Beim Entfernen von Elementen kann auf die */
/* Fallunterscheidung allerdings nicht verzichtet werden.                    */
/*****************************************************************************/

#include "object/queue.h"

// ENQUEUE: Das angegebene Element wird an das Ende der Liste angefuegt.

void Queue::enqueue (Chain* item)
 { 
   item->next = 0;       // Das neue Element besitzt noch keinen Nachfolger.
   *tail = item;         // Das Element an das Ende der Liste anfuegen
   //Wenn hier interrupted, dann AUA
   tail = &(item->next); // und den tail Zeiger aktualisieren.
 }

 void Queue::enqueue_interrupt_resistent (Chain* item)
 {
   item->next = 0;
   Chain** last = tail; //Wir merken uns den derzeitigen letzten
   tail = &item->next; //ab hier hängt das Element in der Liste (wird von anderen Elementen gefunden)
   while(!*last) {
     last = &((*last)->next);
    }
   *last = item; //Position des Elements wird korrigiert
 }

// DEQUEUE: Liefert das erste Element der Liste und entfernt es gleichzeitig
//          aus dieser. Wenn die Liste gar kein Element enthaelt, wird der
//          Null-Zeiger zurueckgeliefert.

Chain* Queue::dequeue ()
 {
   Chain* item;

   item = head;            // Der head Zeiger bezeichnet das erste Element.
   if (item)               // oder Null, wenn die Liste leer ist.
    {
      head = item->next;   // Das erste Element aus der Liste ausklinken.
      if (!head)           // Wenn die Liste nun leer ist, muss der tail
	tail = &head;      // Zeiger wieder auf den head verweisen.
      else                 // sonst nur noch
	item->next = 0;    // den Eintrag ueber den Nachfolger loeschen.
    }
   return item;
 }


 Chain* Queue::dequeue_interrupt_resistent() //Bedingung: dequeue kann nur von enqueue unterbrochen werden
 {
    Chain* item = head;

    if(!head) {
      return 0;
    }

    if(head->next) {
      head = head->next;
      return item;
    }


    tail = &head;
    Chain* lost = item->next;
    while(lost) {
      Chain* x = lost->next;
      enqueue_interrupt_resistent(lost); //Nachfolger werden nicht auf null gesetzt (siehe Implementierung der Methode)
      lost = x;
    }

    return item;
 }



// REMOVE: Sucht das angegebene Element in der Liste und entfernt es.

void Queue::remove (Chain* item)
 {
   Chain* cur;

   if (head)
    {
      cur = head;            // Die Suche beginnt am Kopf der Liste.
      if (item == cur)       // Wenn das erste Element bereits das gesuchte
	dequeue ();          // ist, genuegt dequeue zum Entfernen.
      else
       {
	 while (cur->next && item != cur->next)  // Suchen, bis das Ende der
	   { cur = cur->next;                    // Liste erreicht oder das
	   }                                     // naechste Element das
	                                         // gesuchte ist.
	 if (cur->next)
	  {
	    cur->next = item->next;   // Das Element aus der Liste ausklinken.
	    item->next = 0;      // Den Eintrag ueber den Nachfolger loeschen.

	    if (!cur->next)           // Wenn cur jetzt keinen Nachfolger hat,
	      tail = &(cur->next);    // muss tail aktualisiert werden.
	  }
       }
    }
 }
