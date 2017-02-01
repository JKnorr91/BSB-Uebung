#include "game/monster_b.h"
#include "./domain.h"
#include "user/debug.h"

	Monster_b::Monster_b() : Monster(5) {
		setPositionRestrictionX(1,1);
		getHitbox()->setSize(3, 2);
		getHitbox()->setOffset(-1, -1);
	}

	bool Monster_b::update() {
		if (cooldown > 0) {
			cooldown--;
		} else if (getPosY() >= 1 && isAlive() ) {
			cooldown = 30;
			setPos(getPosX(),getPosY()+1);
		}

		return isAlive() && getPosY() < 25;
	}

	void Monster_b::render() { //erstes byte Hintergrund, zweites Schriftfarbe

		int color1 = 0x09;	//hellblau
		int color2 = 0x4e;	//gelb auf Rot
		

		/*
			"\W/"
			" V "
		*/

		//blue Monster
		kout.preShow(getX1()  , getY1()   , '\\', color1);
		kout.preShow(getX1()+1, getY1()   , 'W', color1);
		kout.preShow(getX1()+2, getY1()   , '/', color1);

		kout.preShow(getX1()+1, getY1()+1 , 'V', color1);	
	}
