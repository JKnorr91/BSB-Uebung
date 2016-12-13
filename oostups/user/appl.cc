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
#include "thread/dispatch.h"

	Application::Application(void* tos, int idIn, int xin, int yin) :  Coroutine(tos) {
		id = idIn;
		x=xin;
		y=yin;
	}

	void Application::action ()
 	{
		int a;
		int b;
 		while (true) {
			{Secure section;
				kout.getpos(a, b);

				/*kout.setpos(5, 5);
				kout << "Ich: " << id << ", x=" << x <<el;
				kout.setpos(5, 6);
				kout << "Next: " << next->id << ", x=" << next->x <<el;*/

				kout.setpos(x, y);
				kout << output_num << el;

				output_num++;
				kout.setpos(a, b);
			}
			dispatcher.dispatch(*next);
			//resume(*next);
		}
 	}
