#ifndef __Monster_include__
#define __Monster_include__

#include "game/entity.h"

class Monster : public Entity {

private:
    Monster (const Monster &copy); // Verhindere Kopieren
	int moveWaitTimerX;
	int moveWaitTimerY;
protected:
	int life;
	int moveWaitX;
	int moveWaitY;
	int moveX;
	int moveY;
public:
	Monster(int initialLife);
	int getLife();
	void setLife(int value);
	void modifyLife(int value);
	bool isAlive();
	bool isDead();
	bool update();
	virtual void updateMonster();
	void hit();
 };
#endif
