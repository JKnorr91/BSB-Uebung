/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Klasse von Objekten, die in der Lage sind, Unterbrechungen zu behandeln.  */
/*****************************************************************************/

#include "guard/gate.h"

	Gate::Gate() {
		queued(false);
	}

	void Gate::queued(bool q) {
		isQueued = q;
	}

	bool Gate::queued() {
		return isQueued;
	}
