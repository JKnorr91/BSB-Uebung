#include "./gp_over.h"
#include "./invaders.h"

	GameOver::GameOver() {
	}

	void GameOver::start() {
		selectedContinue = false;
	}

	void GameOver::update() {
		if (keyboard.isPressed(Key::scan::left)) {
			selectedContinue = true;
		} else if (keyboard.isPressed(Key::scan::right)) {
			selectedContinue = false;
		} else if (keyboard.isPressed(Key::scan::space)) {
			appInv.setPhase(&(appInv.domain));
		}
	}

	void GameOver::render() {
		kout.setpos(40 - 9 / 2, 12);
		kout << "Game Over" << el;
		kout.setpos(40 - 9 / 2, 15);
		kout << "Continue?" << el;
		kout.hide();

		if (selectedContinue) {
			kout.preShow(40-5, 17, '>', 0x0f);
		}
		kout.preShow(40-4, 17, 'Y', 0x0f);
		kout.preShow(40-3, 17, 'e', 0x0f);
		kout.preShow(40-2, 17, 's', 0x0f);

		if (!selectedContinue) {
			kout.preShow(40+2, 17, '>', 0x0f);
		}
		kout.preShow(40+3, 17, 'N', 0x0f);
		kout.preShow(40+4, 17, 'o', 0x0f);
	}
