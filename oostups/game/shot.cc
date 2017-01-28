#include "./shot.h"

	Shot::Shot() : Entity(0,0) {}

	Shot::Shot(int initialX, int initialY) : Entity(initialX, initialY) {}

	bool Shot::update(Key* nowPressed) {
        return true;
	}

	void Shot::render() { //erstes byte Hintergrund, zweites Schriftfarbe
		int fireStyle = 0xce;

		//SpaceShuttle Spitze
		kout.show(getPosX(), getPosY(), 'O', fireStyle);
	}