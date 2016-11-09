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
		output_num = 123;
	}


	void Application::action ()
 	{
		int x;
		int y;
 		while (true) {
			cpu.disable_int();
			kout.getpos(x, y);
			kout.setpos(5, 10);
			kout << output_num << el;
			kout.setpos(x, y);
			cpu.enable_int();
		}
 	}
