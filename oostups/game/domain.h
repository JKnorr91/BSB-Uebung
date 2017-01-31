#ifndef __Domain_include__
#define __Domain_include__

#include "game/entity.h"
#include "object/list.h"
#include "./player.h"
#include "./shot.h"
#include "./gameKey.h"
#include "./monster_g.h"
#include "./monster_b.h"

class Domain {
    private:
        Domain (const Domain &copy); // Verhindere Kopieren
        List entityList;
        Player player;
        MonsterGreen monster;
        Monster_b monster2;

        int currentShotIndex;
        Shot shot[25];
    public:
        Domain();
        void addEntity(Entity* entity);
        void createShot(int x, int y);
        void update();
        void render();
};
#endif