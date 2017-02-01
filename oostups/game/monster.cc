#include "game/monster.h"

	Monster::Monster(int initialLife) : Entity(0,0) {
		life = initialLife;
	}

	int Monster::getLife() {
		return life;
	}

	void Monster::setLife(int value) {
		if (value < 0) {
			value = 0;
		}
		life = value;
	}

	void Monster::modifyLife(int value) {
		setLife(getLife() + value);
	}

	bool Monster::isAlive() {
		return getLife() > 0;
	}

	bool Monster::isDead() {
		return getLife() <= 0;
	}
