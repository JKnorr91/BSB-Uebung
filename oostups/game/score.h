#ifndef __Score_include__
#define __Score_include__

#include "device/cgastr.h"
#include "game/player.h"
#include "game/monster.h"

class Score : public Entity {
private:
    Score (const Score &copy); // Verhindere Kopieren
	int score;
	int scoreDisplay;
public:
	Score();
	bool update();
	void render();
	void reset();
	int getScore();
	void onMonsterHit(Monster* monster);
	void onMonsterDestroyed(Monster* monster);
	void onPlayerHit(Player* player);
	void onShotFired(Player* player);
 };
#endif
