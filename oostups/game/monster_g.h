#ifndef __Player_include__
#define __Player_include__

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
	MonsterGreen(int initialX, int initialY);
	bool update();
	void render();
 };
#endif
