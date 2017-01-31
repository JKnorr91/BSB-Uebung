#include "game/monster_b.h"
#include "./domain.h"
#include "user/debug.h"

	Monster_b::Monster_b() : Entity(0,0) {
		life = 5;
		setPositionRestrictionX(1,1);
	}

	Monster_b::Monster_b(int initialX, int initialY) : Entity(initialX, initialY) {
		life = 5;
		setPositionRestrictionX(1,1);
	}

	void Monster_b::setDomain(Domain* domain) {
		this->domain = domain;
	}

	bool Monster_b::update() {
		if (cooldown > 0) {
			cooldown--;
		} else if (getPosY() >= 1 && life > 0 ) {
			cooldown = 30;
			setPos(getPosX(),getPosY()+1);
		}

		return life > 0;
	}

	void Monster_b::render() { //erstes byte Hintergrund, zweites Schriftfarbe

		int color1 = 0x09;	//hellblau
		int color2 = 0x4e;	//gelb auf Rot
		

		/*
			"\W/"
			" V "
		*/

		//blue Monster
		kout.show(getPosX()-1, getPosY()   , '\\', color1);
		kout.show(getPosX()  , getPosY()   , 'W', color1);
		kout.show(getPosX()+1, getPosY()   , '/', color1);

		kout.show(getPosX()  , getPosY()+1 , 'V', color1);

		

		

		
	}
