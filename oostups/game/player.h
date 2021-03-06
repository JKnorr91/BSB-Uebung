#ifndef __Player_include__
#define __Player_include__

#include "device/cgastr.h"
#include "machine/key.h"
#include "game/entity.h"

class Domain;

class Player : public Entity {

private:
	static char lifeToCharTable[];

    Player (const Player &copy); // Verhindere Kopieren
	int life;
	int cooldown;
public:
	Player();
	bool update();
	void render();
	void reset();
	void onHit();
	bool isAlive();
 };
#endif
