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

#include "game/invaders.h"

	Invaders::Invaders(void* tos) :  Thread(tos) {
		initializeGame();
	}

	void Invaders::initializeGame() {
		Player player(40, 22);
		Chain* playerChain = *((Chain) player);

		entityList.enqueue(playerChain);
	}

	void Invaders::action() {
 		while (true) {
			updateModel();

			cgasem.p();
			render();
			cgasem.v();

			buzzer.set(20);
			buzzer.sleep();
		}
 	}

	void Invaders::updateModel() {
		if (!inputThr.keyValid) {
			return;
		}
		Key k = inputThr.keyNow;
		inputThr.keyValid = false;
		
		if(k.ctrl() && k.ascii() == 'c'){
			organizer.exit();
		}

		Chain* current = entityList.first();
		while(current) {
			Chain* next = current->next;

       		Entity* curEntity = (Entity*) current;
			if (!(curEntity->update(k))) {
				entityList.remove(current);
			}
        	current = next;
    	}
	}

	void Invaders::render() {
		kout.screenClear();

		Chain* current = entityList.first();
		while(current) {
			Chain* next = current->next;

       		Entity* curEntity = (Entity*) current;
			curEntity->render();

        	current = next;
    	}
	}
