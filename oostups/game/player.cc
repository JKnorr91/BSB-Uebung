#include "game/player.h"
#include "./domain.h"
#include "syscall/guarded_keyboard.h"
#include "user/debug.h"

	Player::Player() : Entity(0,0) {
		life = 5;
		setPositionRestrictionX(2,2);
	}

	Player::Player(int initialX, int initialY) : Entity(initialX, initialY) {
		life = 5;
		setPositionRestrictionX(2,2);
	}

	void Player::setDomain(Domain* domain) {
		this->domain = domain;
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
			domain->createShot(getPosX(), getPosY()-3);
		
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
