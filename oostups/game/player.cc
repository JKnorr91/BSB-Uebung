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
		kout.preShow(getPosX(), getPosY()-2, ' ', shuttleCaseStyle);

		kout.preShow(getPosX()-1, getPosY()-1, ' ', shuttleCaseStyle);
		kout.preShow(getPosX(), getPosY()-1, ' ', shuttleCaseStyle);
		kout.preShow(getPosX()+1, getPosY()-1, ' ', shuttleCaseStyle);

		kout.preShow(getPosX()-2, getPosY(), ' ', shuttleCaseStyle);
		kout.preShow(getPosX()-1, getPosY(), ' ', shuttleCaseStyle);
		kout.preShow(getPosX(), getPosY(), ' ', shuttleCaseStyle);
		kout.preShow(getPosX()+1, getPosY(), ' ', shuttleCaseStyle);
		kout.preShow(getPosX()+2, getPosY(), ' ', shuttleCaseStyle);

		//SpaceShuttle Antrieb
		kout.preShow(getPosX()-1, getPosY()+1, 'V', fireStyle);
		kout.preShow(getPosX(), getPosY()+1, 'V', fireStyle);
		kout.preShow(getPosX()+1, getPosY()+1, 'V', fireStyle);
	}
