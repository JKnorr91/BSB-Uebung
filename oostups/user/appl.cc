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
			cgasem.p();
			kout.getpos(a, b);
			kout.setpos(x, y);
			kout << output_num << el;
			kout.setpos(a,b);
			cgasem.v();
			output_num++;
			
			if(output_num > 1000000 * id) {
				organizer.exit();
				//scheduler.kill(*nextApp);
			}
			//scheduler.resume();
			//resume(*next);
		}
 	}
