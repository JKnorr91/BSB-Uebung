#include "game/player.h"
#include "./domain.h"
#include "syscall/guarded_keyboard.h"
#include "user/debug.h"

	char Player::lifeToCharTable[] = 
			{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	Player::Player() : Entity(0,0) {
		fullReset();
	}

	void Player::reset() {
		life = 4;
		setPositionRestrictionX(2,2);
		getHitbox()->setSize(5, 4);
		getHitbox()->setOffset(-2, -1);
	}

	void Player::onHit() {
		if (isAlive()) {
			life--;
			renderInverted = 4;
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
		int fireStyle = wasHit() ? 0xec : 0xce;
		int shuttleCaseStyle = wasHit() ? 0xd0 : 0xf0;
		int lifeCharStyle = 0xf0;

		int lifeIdx = life % 10;
		char lifeChar = lifeToCharTable[lifeIdx];

		//SpaceShuttle Spitze
		kout.preShow(getX1()+2, getY1()+0, ' ', shuttleCaseStyle);

		kout.preShow(getX1()+1, getY1()+1, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+2, getY1()+1, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+3, getY1()+1, ' ', shuttleCaseStyle);

		kout.preShow(getX1()+0, getY1()+2, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+1, getY1()+2, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+2, getY1()+2, lifeChar, shuttleCaseStyle);
		kout.preShow(getX1()+3, getY1()+2, ' ', shuttleCaseStyle);
		kout.preShow(getX1()+4, getY1()+2, ' ', shuttleCaseStyle);

		//SpaceShuttle Antrieb
		kout.preShow(getX1()+1, getY1()+3, 'V', fireStyle);
		kout.preShow(getX1()+2, getY1()+3, 'V', fireStyle);
		kout.preShow(getX1()+3, getY1()+3, 'V', fireStyle);

		rendered();
	}
