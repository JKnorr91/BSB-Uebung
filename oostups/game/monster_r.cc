#include "game/monster_r.h"

	MonsterRed::MonsterRed() : Monster() {
		//fullReset();
	}

	void MonsterRed::resetMonster() {
		setLife(4);
		moveWaitY = 16;
		moveY = 1;
		moveWaitX = 3;
		moveX = 1;
		moveXDirection = true;
		setPositionRestrictionX(1, 1);
		getHitbox()->setSize(3, 3);
		getHitbox()->setOffset(-1, -1);
	}

	void MonsterRed::updateMonster() {
		if (moveXDirection) {
			moveX = 1;
			if (getX2() >= 78) {
				moveXDirection = !moveXDirection;
			}
		} else {
			moveX = -1;
			if (getX1() <= 2) {
				moveXDirection = !moveXDirection;
			}
		}
	}

	void MonsterRed::render() {
		/*
		 * Schema
		 * /#\ 
		 *  A
		 * T T 
		 */

		renderExplosion();

		if(isAlive()) {
			int styleYellow = wasHit() ? 0xff : 0xee;
			int styleRed = wasHit() ? 0xc0 : 0x0c;
			int styleRed2 = wasHit() ? 0xec : 0xce;

			//Zeile 1
			kout.preShow(getX1()+0, getY1()+0, '/', styleRed);
			kout.preShow(getX1()+1, getY1()+0, ' ', styleYellow);
			kout.preShow(getX1()+2, getY1()+0, '\\', styleRed);
			//Zeile 2
			//kout.preShow(getX1()+0, getY1()+1, ' ', styleRed);
			kout.preShow(getX1()+1, getY1()+1, 'A', styleRed2);
			//kout.preShow(getX1()+2, getY1()+1, ' ', styleRed);
			//Zeile 3
			kout.preShow(getX1()+0, getY1()+2, 'T', styleRed);
			//kout.preShow(getX1()+1, getY1()+2, ' ', styleRed);
			kout.preShow(getX1()+2, getY1()+2, 'T', styleRed);

		}
		
		rendered();
	}
