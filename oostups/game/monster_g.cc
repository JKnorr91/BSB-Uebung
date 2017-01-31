#include "game/monster_g.h"

	MonsterGreen::MonsterGreen() : Entity(0,0) {
		life = 3;
		shiftPhase = 0;
		shiftGrow = true;
		setPositionRestrictionX(2,2);
	}

	MonsterGreen::MonsterGreen(int initialX, int initialY) : Entity(initialX, initialY) {
		life = 3;
		shiftPhase = 0;
		shiftGrow = true;
		setPositionRestrictionX(2,2);
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
		setPos(getPosX() + shiftPhase, getPosY()+1);
		return life > 0 && getPosY() < 25;
	}

	void MonsterGreen::render() { //erstes byte Hintergrund, zweites Schriftfarbe
		/*
		 * Schema
		 *  ### 
		 * #*#*#
		 *  ### 
		 * #   #
		 */
		int styleGreen = 0x10;
		int styleRed = 0x12;

		//Zeile 1
		//kout.show(getPosX()-2, getPosY()-2, ' ', styleGreen);
		kout.show(getPosX()-1, getPosY()-2, ' ', styleGreen);
		kout.show(getPosX()+0, getPosY()-2, ' ', styleGreen);
		kout.show(getPosX()+1, getPosY()-2, ' ', styleGreen);
		//kout.show(getPosX()+2, getPosY()-2, ' ', styleGreen);
		//Zeile 2
		kout.show(getPosX()-2, getPosY()-1, ' ', styleGreen);
		kout.show(getPosX()-1, getPosY()-1, ' ', styleRed);
		kout.show(getPosX()+0, getPosY()-1, ' ', styleGreen);
		kout.show(getPosX()+1, getPosY()-1, ' ', styleRed);
		kout.show(getPosX()+2, getPosY()-1, ' ', styleGreen);
		//Zeile 3
		//kout.show(getPosX()-2, getPosY()-0, ' ', styleGreen);
		kout.show(getPosX()-1, getPosY()-0, ' ', styleGreen);
		kout.show(getPosX()+0, getPosY()-0, ' ', styleGreen);
		kout.show(getPosX()+1, getPosY()-0, ' ', styleGreen);
		//kout.show(getPosX()+2, getPosY()-0, ' ', styleGreen);
		//Zeile 4
		kout.show(getPosX()-2, getPosY()+1, ' ', styleGreen);
		//kout.show(getPosX()-1, getPosY()+1, ' ', styleGreen);
		//kout.show(getPosX()+0, getPosY()+1, ' ', styleGreen);
		//kout.show(getPosX()+1, getPosY()+1, ' ', styleGreen);
		kout.show(getPosX()+2, getPosY()+1, ' ', styleGreen);
	}
