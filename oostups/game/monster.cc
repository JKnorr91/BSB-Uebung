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

		if(isDead()) {
			renderExploding = 3;
		}
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

	void Monster::rendered() {
		Entity::rendered();
		renderExploding = renderExploding > 0 ? renderExploding-1 : 0;
	}

	bool Monster::isAlive() {
		return getLife() > 0;
	}

	bool Monster::isDead() {
		return getLife() <= 0;
	}

	bool Monster::update() {
		updateMonster();

		if(isAlive()) {
			if (moveWaitTimerX++ >= moveWaitX) {
				moveWaitTimerX = 0;
				setPos(getPosX() + moveX, getPosY());
			}
			if (moveWaitTimerY++ >= moveWaitY) {
				moveWaitTimerY = 0;
				setPos(getPosX(), getPosY() + moveY);
			}
			return true;
		}
		return renderExploding > 0;
	}

	void Monster::renderExplosion() {

		if(isAlive()) {
			return;
		}

		int fireStyle = wasHit() ? 0xec : 0xce;

		if(renderExploding == 4) {
			kout.preShow(getX1(), getY1(), 'O', fireStyle);
		}
		else if(renderExploding == 3) {
			kout.preShow(getX1(), getY1(), '3', fireStyle);
		}
		else if(renderExploding == 2) {
			kout.preShow(getX1(), getY1(), '2', fireStyle);
		}
		else if(renderExploding == 1) {
			kout.preShow(getX1(), getY1(), '1', fireStyle);
		}

	}

	void Monster::updateMonster() {}
