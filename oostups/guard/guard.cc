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
#include "guard/secure.h"

	Guard::Guard () {
	}
	
	void Guard::leave () {
		cpu.disable_int();
		Gate* gate = (Gate*) queue.dequeue();
		cpu.enable_int();

		while (gate) {
			gate -> epilogue();
			gate -> queued(false);
			
			cpu.disable_int();
			gate = (Gate*) queue.dequeue();
			cpu.enable_int();
		}
		retne();
	}

	void Guard::relay (Gate* item) {
		if (avail()) {
			enter();
			cpu.enable_int();
			item -> epilogue();
			leave();
		} else if (!item -> queued()) {
			item -> queued(true);
			queue.enqueue(item);
		}
	}
