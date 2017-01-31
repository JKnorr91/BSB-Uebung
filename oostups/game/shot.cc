#include "./shot.h"

	Shot::Shot() : Entity(0,0) {}

	Shot::Shot(int initialX, int initialY) : Entity(initialX, initialY) {}

	bool Shot::update() {
        setPos(getPosX(), getPosY()-1);

        return getPosY() >= 0;
	}

	void Shot::render() { //erstes byte Hintergrund, zweites Schriftfarbe
		int shotStyle = 0x0e;

		//SpaceShuttle Spitze
		kout.show(getPosX(), getPosY(), 'O', shotStyle);
	}