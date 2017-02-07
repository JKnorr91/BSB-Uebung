#include "./domain.h"
#include "user/debug.h"
#include "./invaders.h"

Domain::Domain() {}

void Domain::addEntity(Entity* entity) {
    entityList.enqueue(entity);
}

void Domain::start() {
	player.setPos(40,22);
    player.setDomain(this);
    addEntity(&player);

    score.setPos(80-score.getHitbox()->getWidth(), 0);
    addEntity(&score);


    currentShotIndex = 0;
    currentMonsterIndex = 0;

    currentMonsterBlueIndex = 0;
    currentMonsterGreenIndex = 0;
    currentMonsterRedIndex = 0;
    
    cooldown = 3*30;
	actCooldown = cooldown;

}

void Domain::update() {
	if (!player.isAlive()) {
		appInv.setPhase(&appInv.flashAnim);
		return;
	}

    detectCollisions();
    Entity* currentEntity = (Entity*) entityList.first();
    while(currentEntity) {
        Entity* next = (Entity*) currentEntity->next;

        if (!(currentEntity->update())) {
            entityList.remove(currentEntity);
        }
        currentEntity = next;
    }
    if (actCooldown-- <= 0){
			int a, x;
			a = random.number(3);
			x = random.number(79);
			createMonster(a,x,3);
			actCooldown = cooldown--;
	}
}

void Domain::render() {
    Entity* currentEntity = (Entity*) entityList.first();
    while(currentEntity) {
        currentEntity->render();
        currentEntity = (Entity*) currentEntity->next;
    }
}

void Domain::createShot(int x, int y) {
    Shot* currentShot = &shot[currentShotIndex];
	currentShot->fullReset();
    currentShot->setPos(x,y);
	currentShot->setActive(true);
    addEntity(currentShot);

	score.onShotFired(&player);

    currentShotIndex = (currentShotIndex+1) % 25;
}

void Domain::createMonster(unsigned char type, int x, int y) {
    
    Monster* currentMonsterPointer;

    if(type == MonsterType::blue) {
        currentMonsterPointer = (Monster*) &monsterBlue[currentMonsterBlueIndex];
        currentMonsterBlueIndex = (currentMonsterBlueIndex+1)%20;
        debug.out(10,10,"BLUE");
    }
    else if(type == MonsterType::green)  {
        currentMonsterPointer = (Monster*) &monsterGreen[currentMonsterGreenIndex];
        currentMonsterGreenIndex = (currentMonsterGreenIndex+1)%20;
        debug.out(10,11,"GREEN");
    }
    else if(type == MonsterType::red)  {
        currentMonsterPointer = (Monster*) &monsterRed[currentMonsterRedIndex];
        currentMonsterRedIndex = (currentMonsterRedIndex+1)%20;
        debug.out(10,12,"RED");
    }

	currentMonsterPointer->fullReset();
    currentMonsterPointer->setPos(x,y);
    currentMonsterPointer->setDomain(this);
    monster[currentMonsterIndex] = currentMonsterPointer;
    currentMonsterIndex = (currentMonsterIndex+1)%60;
    addEntity(currentMonsterPointer);
}

void Domain::detectCollisions() {
    for(int i = 0; i < currentMonsterIndex; i++) {
		if (monster[i] && monster[i]->isAlive()) {
			for(int j = 0; j < 25; j++) {
		        if(shot[j].isActive() && monster[i]->hasCollision(&shot[j])) {
					shot[j].setActive(false);
		            monster[i]->hit();

					score.onMonsterHit(monster[i]);

		            if(monster[i]->isDead()) {
		                monster[i] = 0;
						score.onMonsterDestroyed(monster[i]);
		            }
		        }
		    }
			if ((monster[i]->isAlive() && monster[i]->hasCollision(&player)) || monster[i]->getY2() >= 25) {
				player.onHit();
				score.onPlayerHit(&player);

				monster[i]->setLife(0);
				monster[i] = 0;
			}
		}
    }
}
