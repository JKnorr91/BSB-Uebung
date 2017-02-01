#ifndef __Monster_include__
#define __Monster_include__

#include "game/entity.h"

class Monster : public Entity {

protected:
	int life;
public:
	Monster(int initialLife);
	int getLife();
	void setLife(int value);
	void modifyLife(int value);
	bool isAlive();
	bool isDead();
 };
#endif
