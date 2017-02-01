#include "game/hitbox.h"

	Hitbox::Hitbox() {
		x = y = w = h = ox = oy = 0;
	}

	int Hitbox::getOriginX() {
		return x;
	}

	int Hitbox::getOriginY() {
		return y;
	}

	int Hitbox::getOffsetX() {
		return ox;
	}

	int Hitbox::getOffsetY() {
		return oy;
	}

	int Hitbox::getWidth() {
		return w;
	}

	int Hitbox::getHeight() {
		return h;
	}

	int Hitbox::getX1() {
		return x + ox;
	}

	int Hitbox::getY1() {
		return y + oy;
	}

	int Hitbox::getX2() {
		return x + w + ox;
	}

	int Hitbox::getY2() {
		return y + h + oy;
	}

	void Hitbox::setX(int value) {
		x = value;
	}

	void Hitbox::setY(int value) {
		y = value;
	}

	void Hitbox::setWidth(int value) {
		w = value;
	}

	void Hitbox::setHeight(int value) {
		h = value;
	}

	void Hitbox::setOffsetX(int value) {
		ox = value;
	}

	void Hitbox::setOffsetY(int value) {
		oy = value;
	}

	void Hitbox::setPos(int posX, int posY) {
		setX(posX);
		setY(posY);
	}

	void Hitbox::setSize(int sizeX, int sizeY) {
		setWidth(sizeX);
		setHeight(sizeY);
	}

	void Hitbox::setOffset(int offsetX, int offsetY) {
		setOffsetX(offsetX);
		setOffsetY(offsetY);
	}

	bool Hitbox::contains(int x, int y) {
		return x >= getX1() && x <= getX2() && y >= getY1() && y <= getY2();
	}

	bool Hitbox::intersects(int x1, int y1, int x2, int y2) {
		return getX1() < x2 && getX2() > x1 &&
					getY1() < y2 && getY2() > y1;
	}

	bool Hitbox::intersects(Hitbox* other) {
		return intersects(other->getX1(), other->getY1(), other->getX2(), other->getY2());
	}
