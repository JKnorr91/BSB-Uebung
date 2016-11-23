/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Zentrale Unterbrechungsbehandlungsroutine des Systems.                    */
/* Der Parameter gibt die Nummer des aufgetretenen Interrupts an.            */
/*****************************************************************************/

/* INCLUDES */
#include "device/cgastr.h"
#include "machine/plugbox.h"
#include "device/panic.h"
#include "device/keyboard.h"
#include "guard/guard.h"
#include "machine/cpu.h"
/* FUNKTIONEN */
               
extern "C" void guardian (unsigned int slot);

/*
 * Wird automatisch bei einem interrupt aufgerufen.
 * Muss den interrupt an die Interrupt-Behandlung weiterreichen.
 */
	void guardian (unsigned int slot)
	{
		Gate& gate = plugbox.report(slot);
		bool needsEpilogue = gate.prologue();
		if (needsEpilogue) {
			guard.relay(&gate);
		}
		//cpu.enable_int(); Automatisch
	}
