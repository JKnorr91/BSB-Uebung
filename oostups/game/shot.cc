#include "./shot.h"

	Shot::Shot() : Entity(0,0) {
		active = true;
	}

	Shot::Shot(int initialX, int initialY) : Entity(initialX, initialY) {
		active = true;
	}

	bool Shot::update() {
        setPos(getPosX(), getPosY()-1);
        return getPosY() >= 0 && isActive();
	}

	void Shot::render() { //erstes byte Hintergrund, zweites Schriftfarbe
		int shotStyle = 0x0e;

		//SpaceShuttle Spitze
		kout.show(getPosX(), getPosY(), 'O', shotStyle);
	}

	void Shot::setActive(bool value) {
		active = value;
	}

	bool Shot::isActive() {
		return active;
	}
