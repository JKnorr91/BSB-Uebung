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

#include "game/entity.h"

	Entity::Entity() {}

	Entity::Entity(int initialX, int initialY) {
		setPos(initialX, initialY);
	}

	int Entity::getPosX() {
		return posX;
	}

	int Entity::getPosY() {
		return posY;
	}

	void Entity::setPos(int x, int y) {
		if (x < 0) {
			x = 0;
		} else if (x >= 80) {
			x = 79;
		}
		if (y < 0) {
			y = 0;
		} else if (y >= 25) {
			y = 24;
		}
		posX = x;
		posY = y;
	}
