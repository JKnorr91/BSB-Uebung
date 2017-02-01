#include "game/monster_r.h"

	MonsterRed::MonsterRed() : Monster(4) {
		moveYCounter = 0;
		moveXDirection = true;
		setPositionRestrictionX(1, 1);
		getHitbox()->setSize(3, 3);
		getHitbox()->setOffset(-1, -1);
	}

	bool MonsterRed::update() {
		int moveX = 0;
		int moveY = 0;
		if (moveXDirection) {
			moveX = 1;
			if (getX2() >= 78) {
				moveXDirection = !moveXDirection;
			}
		} else {
			moveX = -1;
			if (getX2() <= 2) {
				moveXDirection = !moveXDirection;
			}
		}
		if (moveYCounter++ >= 16) {
			moveYCounter = 0;
			moveY = 1;
		}
		setPos(getPosX() + moveX, getPosY() + moveY);
		return isAlive() && getPosY() < 25;
	}

	void MonsterRed::render() {
		/*
		 * Schema
		 * /#\ 
		 *  A
		 * T T 
		 */
		int styleYellow = 0xee;
		//int styleRed = 0xcc;
		int styleRed2 = 0xce;

		//Zeile 1
		kout.preShow(getX1()+0, getY1()+0, '/', styleRed2);
		kout.preShow(getX1()+1, getY1()+0, ' ', styleYellow);
		kout.preShow(getX1()+2, getY1()+0, '\\', styleRed2);
		//Zeile 2
		//kout.preShow(getX1()+0, getY1()+1, ' ', styleRed);
		kout.preShow(getX1()+1, getY1()+1, 'A', styleRed2);
		//kout.preShow(getX1()+2, getY1()+1, ' ', styleRed);
		//Zeile 3
		kout.preShow(getX1()+0, getY1()+2, 'T', styleRed2);
		//kout.preShow(getX1()+1, getY1()+2, ' ', styleRed);
		kout.preShow(getX1()+2, getY1()+2, 'T', styleRed2);
	}
