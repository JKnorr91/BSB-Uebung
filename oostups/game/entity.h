#ifndef __Entity_include__
#define __Entity_include__

#include "device/cgastr.h"
#include "object/chain.h"
#include "machine/key.h"

class Entity : public Chain {

private:
    Entity (const Entity &copy); // Verhindere Kopieren
protected:
	int posX;
	int posY;
	int restrictionXLeft;
	int restrictionXRight;
public:
	Entity();
	Entity(int initialX, int initialY);
	virtual bool update(Key* nowPressed) = 0;
	virtual void render() = 0;
	int getPosX();
	int getPosY();
	void setPositionRestrictionX(int restrictionLeft, int restrictionRight);
	void setPos(int x, int y);
 };
#endif