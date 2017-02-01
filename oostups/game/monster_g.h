#ifndef __MonsterGreen_include__
#define __MonsterGreen_include__

#include "game/entity.h"

class Domain;

class MonsterGreen : public Entity {

private:
    MonsterGreen (const MonsterGreen &copy); // Verhindere Kopieren
	int life;
	int shiftPhase;
	bool shiftGrow;
public:
	MonsterGreen();
	bool update();
	void render();
 };
#endif
