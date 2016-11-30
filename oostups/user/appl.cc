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
#include "guard/secure.h"

	Application::Application(void *tos) :  Coroutine(tos) {
	}


	void Application::action ()
 	{
		int x;
		int y;
 		while (true) {
			{Secure section;

				kout.getpos(x, y);
				kout.setpos(5, 10);
				kout << output_num << el;
				output_num++;
				kout.setpos(x, y);
			}
			//cpu.disable_int();
			//kout.getpos(x, y);
			
			//kout.setpos(x, y);
			//cpu.enable_int();
		}
 	}
