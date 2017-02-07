#ifndef __FlashAnimation_include__
#define __FlashAnimation_include__

#include "device/cgastr.h"
#include "game/game_phase.h"

class Invaders;

class FlashAnimation : public GamePhase {
private:
    FlashAnimation (const FlashAnimation &copy); // Verhindere Kopieren
	int counter;
public:
	FlashAnimation();
	void start();
	void update();
	void render();
 };
#endif
