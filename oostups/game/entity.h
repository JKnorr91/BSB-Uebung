#ifndef __Entity_include__
#define __Entity_include__

#include "device/cgastr.h"
#include "object/chain.h"
#include "machine/key.h"
#include "game/hitbox.h"

class Domain;

class Entity : public Chain {

private:
    Entity (const Entity &copy); // Verhindere Kopieren
protected:
	Domain* domain;
	Hitbox hb;
	int restrictionXLeft;
	int restrictionXRight;
	int renderInverted;
	bool wasHit();
	void rendered();
public:
	Entity();
	Entity(int initialX, int initialY);
	void setDomain(Domain* domain);
	virtual bool update() = 0;
	virtual void render() = 0;
	Hitbox* getHitbox();
	bool hasCollision(Entity* other);
	bool hasCollision(Hitbox* hitbox);
	int getPosX();
	int getPosY();
	int getX1();
	int getY1();
	int getX2();
	int getY2();
	void setPositionRestrictionX(int restrictionLeft, int restrictionRight);
	void setPos(int x, int y);
 };
#endif
