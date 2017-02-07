#ifndef __Domain_include__
#define __Domain_include__

#include "game/game_phase.h"
#include "game/entity.h"
#include "object/list.h"
#include "./player.h"
#include "./score.h"
#include "./shot.h"
#include "./gameKey.h"
#include "./monster_g.h"
#include "./monster_b.h"
#include "./monster_r.h"
#include "./monster.h"
#include "library/random.h" 

class Invaders;

class Domain : public GamePhase {
    private:
        Domain (const Domain &copy); // Verhindere Kopieren
        List entityList;
        Player player;
		Score score;

        const static int monstercounter = 30;

        MonsterGreen monsterGreen[monstercounter];
        MonsterBlue monsterBlue[monstercounter];
        MonsterRed monsterRed[monstercounter];


        int currentShotIndex;
        Shot shot[25];

        int currentMonsterIndex;
        Monster* monster[3*monstercounter];
        
        void detectCollisions();

        int cooldown;
	    int actCooldown;

    public:
        Domain();
        void addEntity(Entity* entity);
        void createShot(int x, int y);
        void createMonster(unsigned char type, int x, int y);
        void update();
        void render();
		void start();

        struct MonsterType { enum {
            green=0,
            blue=1,
            red=2
        };};
};
#endif
