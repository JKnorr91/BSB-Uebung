#ifndef __Player_include__
#define __Player_include__

#include "device/cgastr.h"
#include "machine/key.h"
#include "game/entity.h"

class Player : public Entity {

private:
    Player (const Player &copy); // Verhindere Kopieren
	int life;
public:
	Player();
	Player(int initialX, int initialY);
	bool update(Key* nowPressed);
	void render();
 };
#endif
