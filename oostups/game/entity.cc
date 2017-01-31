#include "game/entity.h"
#include "./domain.h"

	Entity::Entity(){
		setPos(0,0);
		setPositionRestrictionX(0,0);
	}

	Entity::Entity(int initialX, int initialY) {
		setPos(initialX, initialY);
		setPositionRestrictionX(0,0);
	}

	void Entity::setDomain(Domain* domain) {
		this->domain = domain;
	}

	void Entity::setPositionRestrictionX(int restrictionLeft, int restrictionRight) {
		restrictionXLeft = restrictionLeft;
		restrictionXRight = restrictionRight;
	}

	int Entity::getPosX() {
		return posX;
	}

	int Entity::getPosY() {
		return posY;
	}

	void Entity::setPos(int x, int y) {
		if (x < restrictionXLeft) {
			x = restrictionXLeft;
		} else if (x >= 80 - restrictionXRight) {
			x = 79 - restrictionXRight;
		}
		/*if (y < 0) {
			y = 0;
		} else if (y >= 25) {
			y = 24;
		}*/
		posX = x;
		posY = y;
	}
