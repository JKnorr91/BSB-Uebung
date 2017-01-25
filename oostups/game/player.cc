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

#include "game/player.h"

	Player::Player() {
		life = 5;
	}

	Player::Player(int initialX, int initialY) : Entity(initialX, initialY) {
		life = 5;
	}

	bool Player::update(Key nowPressed) {
		if (nowPressed.scancode() == Key::scan::left) {
			setPos(getPosX() - 1, getPosY());
		} else if (nowPressed.scancode() == Key::scan::right) {
			setPos(getPosX() + 1, getPosY());
		}
		return life > 0;
	}

	void Player::render() {
		kout.show(getPosX(), getPosY(), 'A', 0x0f);
	}
