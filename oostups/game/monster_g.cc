#include "game/monster_g.h"

	MonsterGreen::MonsterGreen() : Monster(3) {
		shiftPhase = 0;
		shiftGrow = true;
		setPositionRestrictionX(2,2);
		getHitbox()->setSize(5, 4);
		getHitbox()->setOffset(-2, -1);
	}

	bool MonsterGreen::update() {
		//setPos(getPosX() - 1, getPosY());
		if (shiftGrow) {
			shiftPhase++;
			if (shiftPhase > 2) {
				shiftGrow = !shiftGrow;
			}
		} else {
			shiftPhase--;
			if (shiftPhase < -2) {
				shiftGrow = !shiftGrow;
			}
		}
		setPos(getPosX() + shiftPhase, getPosY());
		return isAlive() && getPosY() < 25;
	}

	void MonsterGreen::render() { //erstes byte Hintergrund, zweites Schriftfarbe
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
