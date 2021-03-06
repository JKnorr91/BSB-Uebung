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

			if(id == 1) {
				buzzer.set(1000);
				buzzer.sleep();
			}

			/*if(id == 2 && output_num == 10000) {
				keyboard.getkey();
			}*/
			
			if(output_num > 50000 * id) {
				organizer.exit();
				//scheduler.kill(*nextApp);
			}
			//scheduler.resume();
			//resume(*next);
		}
 	}
