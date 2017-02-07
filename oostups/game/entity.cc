#include "game/entity.h"
#include "./domain.h"

	Entity::Entity(){
		setPos(0,0);
		setPositionRestrictionX(0,0);
	}

	Entity::Entity(int initialX, int initialY) {
		setPos(initialX, initialY);
		setPositionRestrictionX(0,0);
	}

	void Entity::setDomain(Domain* domain) {
		this->domain = domain;
	}

	void Entity::setPositionRestrictionX(int restrictionLeft, int restrictionRight) {
		restrictionXLeft = restrictionLeft;
		restrictionXRight = restrictionRight;
	}

	bool Entity::wasHit() {
		return renderInverted > 0;
	}

	void Entity::rendered() {
		renderInverted = renderInverted > 0 ? renderInverted-1 : 0;
	}

	int Entity::getPosX() {
		return hb.getOriginX();
	}

	int Entity::getPosY() {
		return hb.getOriginY();
	}

	Hitbox* Entity::getHitbox() {
		return &hb;
	}

	int Entity::getX1() {
		return hb.getX1();
	}

	int Entity::getY1() {
		return hb.getY1();
	}

	int Entity::getX2() {
		return hb.getX2();
	}

	int Entity::getY2() {
		return hb.getY2();
	}

	bool Entity::hasCollision(Entity* other) {
		return hb.intersects(other->getHitbox());
	}

	bool Entity::hasCollision(Hitbox* hitbox) {
		return hb.intersects(hitbox);
	}

	void Entity::setPos(int x, int y) {
		if (x < restrictionXLeft) {
			x = restrictionXLeft;
		} else if (x >= 80 - restrictionXRight) {
			x = 79 - restrictionXRight;
		}
		/*if (y < 0) {
			y = 0;
		} else if (y >= 25) {
			y = 24;
		}*/
		hb.setPos(x, y);
	}
