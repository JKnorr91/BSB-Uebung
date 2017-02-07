#include "./gp_flash.h"
#include "./invaders.h"

	FlashAnimation::FlashAnimation() {
	}

	void FlashAnimation::start() {
		counter = 0;
	}

	void FlashAnimation::update() {
		counter++;
		if (counter > 60) {
			appInv.setPhase(&(appInv.gameOver));
		}
	}

	void FlashAnimation::render() {
		char colorRed = 0xc0;
		char colorWhite = 0xf0;
		if (counter % 2 == 0) {
			kout.screenClearTo(' ', colorRed);
		} else {
			kout.screenClearTo(' ', colorWhite);
		}
	}
