#ifndef __Monster_b_include__
#define __Monster_b_include__

#include "device/cgastr.h"
#include "machine/key.h"
#include "game/monster.h"

class Domain;

class MonsterBlue : public Monster {

private:
    MonsterBlue (const MonsterBlue &copy); // Verhindere Kopieren
	int cooldown;
	Domain* domain;
public:
	MonsterBlue();
	MonsterBlue(int initialX, int initialY);
	bool update();
	void render();
 };
#endif
