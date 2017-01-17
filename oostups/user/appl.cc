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


	Application::Application(void* tos, int idIn, int xin, int yin) :  Thread(tos) {
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
			if(output_num > 1000000 * id) {
				organizer.exit();
				//scheduler.kill(*nextApp);
			}
			//scheduler.resume();
			//resume(*next);
		}
 	}
