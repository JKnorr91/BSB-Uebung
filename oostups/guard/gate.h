/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Klasse von Objekten, die in der Lage sind, Unterbrechungen zu behandeln.  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__
#include "device/cgastr.h"
#include "machine/cpu.h"

class Gate{
private:
    Gate (const Gate &copy) {}
	bool isQueued;
public:
	Gate();
	virtual bool prologue()=0;
	virtual void epilogue() {};
	void queued(bool q);
	bool queued();
};
#endif
