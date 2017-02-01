#ifndef __MonsterRed_include__
#define __MonsterRed_include__

#include "game/monster.h"

class MonsterRed : public Monster {

private:
    MonsterRed (const MonsterRed &copy); // Verhindere Kopieren
	int moveYCounter;
	int moveXCounter;
	bool moveXDirection;
public:
	MonsterRed();
	void updateMonster();
	void render();
 };
#endif
