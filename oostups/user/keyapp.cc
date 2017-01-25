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

#include "user/keyapp.h"



	KeyApp::KeyApp(void* tos) :  Thread(tos) {}

	void KeyApp::action ()
 	{
 		while (true) {
			Key k = keyboard.getkey();
			
			if(k.ctrl() && k.ascii() == 'c'){
				organizer.exit();
			}

			cgasem.p();
			kout << k.ascii() << el;
			cgasem.v();

			//buzzer.set(500);
			//buzzer.sleep();
		}
 	}
