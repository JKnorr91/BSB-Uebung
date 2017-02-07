#ifndef __Domain_include__
#define __Domain_include__

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

class Domain {
    private:
        Domain (const Domain &copy); // Verhindere Kopieren
        List entityList;
        Player player;
		Score score;

        MonsterGreen monsterGreen[20];
        MonsterBlue monsterBlue[20];
        MonsterRed monsterRed[20];


        int currentShotIndex;
        Shot shot[25];

        int currentMonsterIndex;
        Monster* monster[60];

        int currentMonsterBlueIndex;
        int currentMonsterGreenIndex;
        int currentMonsterRedIndex;
        
        void detectCollisions();
    public:
        Domain();
        void addEntity(Entity* entity);
        void createShot(int x, int y);
        void createMonster(unsigned char type, int x, int y);
        void update();
        void render();

        struct MonsterType { enum {
            green=1,
            blue=2,
            red=3
        };};
};
#endif
