#include "game/monster_g.h"

	MonsterGreen::MonsterGreen() : Monster(3) {
		moveYCounter = 0;
		moveXCounter = 0;
		moveXDirection = true;
		setPositionRestrictionX(2,2);
		getHitbox()->setSize(5, 3);
		getHitbox()->setOffset(-2, -1);
	}

	bool MonsterGreen::update() {
		int moveX = 0;
		int moveY = 0;
		if (moveXDirection) {
			moveX = 1;
			moveXCounter++;
			if (moveXCounter > 4) {
				moveXDirection = !moveXDirection;
			}
		} else {
			moveX = -1;
			moveXCounter--;
			if (moveXCounter < -4) {
				moveXDirection = !moveXDirection;
			}
		}
		if (moveYCounter++ >= 9) {
			moveYCounter = 0;
			moveY = 1;
		}
		setPos(getPosX() + moveX, getPosY() + moveY);
		return isAlive() && getPosY() < 25;
	}

	void MonsterGreen::render() {
		/*
		 * Schema
		 *  ### 
		 * #*#*#
		 *  ### 
		 * #   #
		 */
		int styleGreen = 0xaa;
		int styleRed = 0xcc;

		//Zeile 1
		//kout.preShow(getX1()+0, getY1()+0, ' ', styleGreen);
		kout.preShow(getX1()+1, getY1()+0, ' ', styleGreen);
		kout.preShow(getX1()+2, getY1()+0, ' ', styleGreen);
		kout.preShow(getX1()+3, getY1()+0, ' ', styleGreen);
		//kout.preShow(getX1()+4, getY1()+0, ' ', styleGreen);
		//Zeile 2
		kout.preShow(getX1()+0, getY1()+1, ' ', styleGreen);
		kout.preShow(getX1()+1, getY1()+1, ' ', styleRed);
		kout.preShow(getX1()+2, getY1()+1, ' ', styleGreen);
		kout.preShow(getX1()+3, getY1()+1, ' ', styleRed);
		kout.preShow(getX1()+4, getY1()+1, ' ', styleGreen);
		//Zeile 3
		//kout.preShow(getX1()+0, getY1()+2, ' ', styleGreen);
		kout.preShow(getX1()+1, getY1()+2, ' ', styleGreen);
		kout.preShow(getX1()+2, getY1()+2, ' ', styleGreen);
		kout.preShow(getX1()+3, getY1()+2, ' ', styleGreen);
		//kout.preShow(getX1()+4, getY1()+2, ' ', styleGreen);
		//Zeile 4
		kout.preShow(getX1()+0, getY1()+3, ' ', styleGreen);
		//kout.preShow(getX1()+1, getY1()+3, ' ', styleGreen);
		//kout.preShow(getX1()+2, getY1()+3, ' ', styleGreen);
		//kout.preShow(getX1()+3, getY1()+3, ' ', styleGreen);
		kout.preShow(getX1()+4, getY1()+3, ' ', styleGreen);
	}
