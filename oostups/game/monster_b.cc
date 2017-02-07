#include "game/monster_b.h"
#include "./domain.h"
#include "user/debug.h"

	MonsterBlue::MonsterBlue() : Monster() {
		//fullReset();
	}

	void MonsterBlue::resetMonster() {
		setLife(3);
		setPositionRestrictionX(1,1);
		getHitbox()->setSize(3, 2);
		getHitbox()->setOffset(-1, -1);
		moveWaitY = 15;
		moveY = 1;
	}

	/*void MonsterBlue::updateMonster() {
		if (cooldown > 0) {
			cooldown--;
		} else if (getPosY() >= 1 && isAlive() ) {
			cooldown = 30;
			setPos(getPosX(),getPosY()+1);
		}
	}*/

	void MonsterBlue::render() { //erstes byte Hintergrund, zweites Schriftfarbe

		renderExplosion();

		if(isAlive()) {
			int color1 = wasHit() ? 0x90 : 0x09;	//hellblau
			int color2 = wasHit() ? 0xe4 : 0x4e;	//gelb auf Rot
			

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


		rendered();
	}
