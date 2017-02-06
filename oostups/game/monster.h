#ifndef __Monster_include__
#define __Monster_include__

#include "game/entity.h"

class Monster : public Entity {

private:
    Monster (const Monster &copy); // Verhindere Kopieren
	int moveWaitTimerX;
	int moveWaitTimerY;
	int renderInverted;
protected:
	int life;
	int moveWaitX;
	int moveWaitY;
	int moveX;
	int moveY;
	bool wasHit();
	void rendered();
public:
	Monster(int initialLife);
	void hit();
	int getLife();
	void setLife(int value);
	void modifyLife(int value);
	bool isAlive();
	bool isDead();
	bool update();
	virtual void updateMonster();
 };
#endif
