#ifndef __MonsterGreen_include__
#define __MonsterGreen_include__

#include "game/monster.h"

class MonsterGreen : public Monster {

private:
    MonsterGreen (const MonsterGreen &copy); // Verhindere Kopieren
	int moveXCounter;
	bool moveXDirection;
public:
	MonsterGreen();
	void updateMonster();
	void render();
 };
#endif
