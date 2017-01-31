#include "game/invaders.h"
#include "user/debug.h"

	Invaders::Invaders(void* tos) :  Thread(tos) {
		initializeGame();
	}

	void Invaders::initializeGame() {
		kout.hide();
	}

	void Invaders::action() {
 		while (true) {
			updateDomain();

			cgasem.p();
			renderDomain();
			cgasem.v();

			buzzer.set(1000/30);
			buzzer.sleep();
		}
 	}

	void Invaders::updateDomain() {
		domain.update(&gameKey);
	}

	void Invaders::renderDomain() {
		kout.screenClear();
		domain.render();
	}
