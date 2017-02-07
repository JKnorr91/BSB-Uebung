#include "game/monster.h"

	Monster::Monster(int initialLife) : Entity(0,0) {
		life = initialLife;
		moveWaitTimerX = 0;
		moveWaitTimerY = 0;
		moveWaitX = 0;
		moveWaitY = 0;
		moveX = 0;
		moveY = 0;
		renderInverted = 0;
	}

	void Monster::hit() {
		modifyLife(-1);
		renderInverted = 2;
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

	bool Monster::update() {
		updateMonster();
		if (moveWaitTimerX++ >= moveWaitX) {
			moveWaitTimerX = 0;
			setPos(getPosX() + moveX, getPosY());
		}
		if (moveWaitTimerY++ >= moveWaitY) {
			moveWaitTimerY = 0;
			setPos(getPosX(), getPosY() + moveY);
		}
		return isAlive() && getPosY() < 25;
	}

	void Monster::updateMonster() {}
