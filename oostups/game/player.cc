#include "game/player.h"

	Player::Player() : Entity(0,0) {
		life = 5;
	}

	Player::Player(int initialX, int initialY) : Entity(initialX, initialY) {
		life = 5;
	}

	bool Player::update(Key* nowPressed) {
		if(nowPressed) {
			if (nowPressed->scancode() == Key::scan::left) {
				setPos(getPosX() - 1, getPosY());
			} else if (nowPressed->scancode() == Key::scan::right) {
				setPos(getPosX() + 1, getPosY());
			}
		}
		return life > 0;
	}

	void Player::render() { //erstes byte Hintergrund, zweites Schriftfarbe

		int fireStyle = 0xce;
		int shuttleCaseStyle = 0xf0;

		//SpaceShuttle Spitze
		kout.show(getPosX(), getPosY()-2, ' ', shuttleCaseStyle);

		kout.show(getPosX()-1, getPosY()-1, ' ', shuttleCaseStyle);
		kout.show(getPosX(), getPosY()-1, ' ', shuttleCaseStyle);
		kout.show(getPosX()+1, getPosY()-1, ' ', shuttleCaseStyle);

		kout.show(getPosX()-2, getPosY(), ' ', shuttleCaseStyle);
		kout.show(getPosX()-1, getPosY(), ' ', shuttleCaseStyle);
		kout.show(getPosX(), getPosY(), ' ', shuttleCaseStyle);
		kout.show(getPosX()+1, getPosY(), ' ', shuttleCaseStyle);
		kout.show(getPosX()+2, getPosY(), ' ', shuttleCaseStyle);

		//SpaceShuttle Antrieb
		kout.show(getPosX()-1, getPosY()+1, 'V', fireStyle);
		kout.show(getPosX(), getPosY()+1, 'V', fireStyle);
		kout.show(getPosX()+1, getPosY()+1, 'V', fireStyle);
		

		
	}