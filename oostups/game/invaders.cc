#include "game/invaders.h"
#include "user/debug.h"

	Invaders::Invaders(void* tos) :  Thread(tos) {
	}

	void Invaders::initializeGame() {
		kout.hide();
		setPhase(&domain);
	}

	void Invaders::setPhase(GamePhase* phase) {
		curPhase = phase;
		if (curPhase) {
			curPhase->start();
		}
	}

	void Invaders::action() {
 		while (true) {
			updateGamePhase();

			cgasem.p();
			renderGamePhase();
			cgasem.v();

			buzzer.set(1000/30);
			buzzer.sleep();
		}
 	}

	void Invaders::updateGamePhase() {
		curPhase->update();
	}

	void Invaders::renderGamePhase() {
		kout.screenClear();
		curPhase->render();
		kout.writeSoftwareBuffer();
	}
