#ifndef __GameOver_include__
#define __GameOver_include__

#include "device/cgastr.h"
#include "game/game_phase.h"
#include "syscall/guarded_keyboard.h"

class Invaders;

class GameOver : public GamePhase {
private:
    GameOver (const GameOver &copy); // Verhindere Kopieren
	bool selectedContinue;
	int score;
public:
	GameOver();
	void start();
	void update();
	void render();
	void setScore(int value);
 };
#endif
