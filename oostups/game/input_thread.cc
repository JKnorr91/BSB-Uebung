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

#include "game/input_thread.h"

	InputThread::InputThread(void* tos) :  Thread(tos) {
		keyValid = false;
	}

	void InputThread::action ()
 	{
 		while (true) {
			keyNow = keyboard.getkey();
			gameKey.setKey(&keyNow);
			//keyValid = true;
			//if(keyNow.ctrl() && keyNow.ascii() == 'c'){
				//organizer.exit();
			//}
		}
 	}
