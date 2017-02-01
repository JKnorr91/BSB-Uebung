#ifndef __MonsterGreen_include__
#define __MonsterGreen_include__

#include "game/monster.h"

class Domain;

class MonsterGreen : public Monster {

private:
    MonsterGreen (const MonsterGreen &copy); // Verhindere Kopieren
	int shiftPhase;
	bool shiftGrow;
public:
	MonsterGreen();
	bool update();
	void render();
 };
#endif
