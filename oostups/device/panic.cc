/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/ 
#include "device/panic.h"

	bool Panic::prologue(){
		kout << "Panic::trigger()" <<endl;
		cpu.halt();
	}
