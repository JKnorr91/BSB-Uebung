#ifndef __MonsterGreen_include__
#define __MonsterGreen_include__

#include "game/monster.h"

class MonsterGreen : public Monster {

private:
    MonsterGreen (const MonsterGreen &copy); // Verhindere Kopieren
	int moveYCounter;
	int moveXCounter;
	bool moveXDirection;
public:
	MonsterGreen();
	bool update();
	void render();
 };
#endif
