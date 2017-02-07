#include "game/player.h"
#include "./domain.h"
#include "syscall/guarded_keyboard.h"
#include "user/debug.h"

	Player::Player() : Entity(0,0) {
		life = 2;
		setPositionRestrictionX(2,2);
		getHitbox()->setSize(5, 4);
		getHitbox()->setOffset(-2, -1);
	}

	void Player::onHit() {
		if (isAlive()) {
			life--;
		}
	}

	bool Player::isAlive() {
		return life > 0;
	}

	bool Player::update() {
		if (keyboard.isPressed(Key::scan::left)) {
			setPos(getPosX() - 1, getPosY());
		}

		if (keyboard.isPressed(Key::scan::right)) {
			setPos(getPosX() + 1, getPosY());
		}
		if (cooldown > 0) {
			cooldown--;
		} else if (keyboard.isPressed(Key::scan::space)) {
			cooldown = 5;
			domain->createShot(getPosX(), getPosY()-2);
		
		}

		return life > 0;
	}

	void Player::render() { //erstes byte Hintergrund, zweites Schriftfarbe
		int fireStyle = 0xce;
		int shuttleCaseStyle = 0xf0;

		//SpaceShuttle Spitze
		kout.preShow(getX1()+2, getY1()+0, ' ', shuttleCaseStyle);

		kout.preShow(getX1()+1, getY1()+1, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+2, getY1()+1, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+3, getY1()+1, ' ', shuttleCaseStyle);

		kout.preShow(getX1()+0, getY1()+2, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+1, getY1()+2, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+2, getY1()+2, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+3, getY1()+2, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+4, getY1()+2, ' ', shuttleCaseStyle);

		//SpaceShuttle Antrieb
		kout.preShow(getX1()+1, getY1()+3, 'V', fireStyle);
		kout.preShow(getX1()+2, getY1()+3, 'V', fireStyle);
		kout.preShow(getX1()+3, getY1()+3, 'V', fireStyle);
	}
