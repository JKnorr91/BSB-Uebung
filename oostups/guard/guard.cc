/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

#include "guard/guard.h"

	Guard::Guard () {
	}
	
	void Guard::leave () {
		Gate* gate = (Gate*) queue.dequeue();
		while (gate) {
			gate -> queued(false);
			gate -> epilogue();
			gate = (Gate*) queue.dequeue();
		}
		retne();
	}

	void Guard::relay (Gate* item) {
		if (avail()) {
			item -> epilogue();
		} else {
			item -> queued(true);
			queue.enqueue(item);
		}
	}
