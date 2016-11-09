/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

	Application::Application() {
		output_num = 0;
	}


	void Application::action ()
 	{
		//cpu.disable_int();
 		while (true) {
			kout.setpos(5, 10);
			kout << output_num << el;
		}
		//cpu.enable_int();
 	}
