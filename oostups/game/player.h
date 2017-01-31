#ifndef __Player_include__
#define __Player_include__

#include "device/cgastr.h"
#include "machine/key.h"
#include "game/entity.h"

class Domain;

class Player : public Entity {

private:
    Player (const Player &copy); // Verhindere Kopieren
	int life;
	int cooldown;
public:
	Player();
	Player(int initialX, int initialY);
	void setDomain(Domain* domain);
	bool update();
	void render();
 };
#endif
