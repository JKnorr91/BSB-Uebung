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
/* Hier muesst ihr selbst Code vervollstaendigen */ 
public:
	Gate(){};
	void trigger();
};
#endif
