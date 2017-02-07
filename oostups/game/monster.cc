#include "game/monster.h"

	Monster::Monster() : Entity(0,0) {
		life = 0;
		//fullReset();
	}

	void Monster::reset() {
		life = 0;
		moveWaitTimerX = 0;
		moveWaitTimerY = 0;
		moveWaitX = 0;
		moveWaitY = 0;
		moveX = 0;
		moveY = 0;
		renderInverted = 0;
		resetMonster();
	}

	void Monster::resetMonster() {
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
		if(isDead()) {
			renderExploding = 3;
		}
	}

	void Monster::modifyLife(int value) {
		setLife(getLife() + value);
		if(isDead()) {
			renderExploding = 3;
		}
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
			kout.preShow(getPosX(), getPosY()-1, '\\', fireStyle);
			kout.preShow(getPosX()+1, getPosY()-1, '/', fireStyle);
			kout.preShow(getPosX(), getPosY()+1, '/', fireStyle);
			kout.preShow(getPosX()+1, getPosY()+1, '\\', fireStyle);
		}
		else if(renderExploding == 3) {
			kout.preShow(getPosX(), getPosY()-2, '*', fireStyle);
			kout.preShow(getPosX()+3, getPosY()-2, '*', fireStyle);
			kout.preShow(getPosX()+1, getPosY()-1, '\\', fireStyle);
			kout.preShow(getPosX()+2, getPosY()-1, '/', fireStyle);
			kout.preShow(getPosX()+1, getPosY()+1, '/', fireStyle);
			kout.preShow(getPosX()+2, getPosY()+1, '\\', fireStyle);
			kout.preShow(getPosX(), getPosY()+2, '*', fireStyle);
			kout.preShow(getPosX()+3, getPosY()+2, '*', fireStyle);
		}
		else if(renderExploding == 2) {
			kout.preShow(getPosX(), getPosY()-1, '*', fireStyle);
			kout.preShow(getPosX()+3, getPosY()-1, '*', fireStyle);
			kout.preShow(getPosX()-1, getPosY()-1, ' ', fireStyle);
			kout.preShow(getPosX(), getPosY()-1, ' ', fireStyle);
			kout.preShow(getPosX()-1, getPosY()+1, ' ', fireStyle);
			kout.preShow(getPosX(), getPosY()+1, ' ', fireStyle);
			kout.preShow(getPosX(), getPosY()+1, '*', fireStyle);
			kout.preShow(getPosX()+3, getPosY()+1, '*', fireStyle);
		}
		else if(renderExploding == 1) {
			kout.preShow(getX1(), getPosY()-2, '*', fireStyle);
			kout.preShow(getX1()+3, getPosY()-2, '*', fireStyle);
			kout.preShow(getX1(), getPosY(), '*', fireStyle);
			kout.preShow(getX1()+3, getPosY(), '*', fireStyle);
		}

	}

	void Monster::updateMonster() {}
