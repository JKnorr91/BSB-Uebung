#ifndef __Monster_b_include__
#define __Monster_b_include__

#include "device/cgastr.h"
#include "machine/key.h"
#include "game/monster.h"

class MonsterBlue : public Monster {

private:
    MonsterBlue (const MonsterBlue &copy); // Verhindere Kopieren
	int cooldown;
public:
	MonsterBlue();
	MonsterBlue(int initialX, int initialY);
	//void updateMonster();
	void render();
	void resetMonster();
 };
#endif
