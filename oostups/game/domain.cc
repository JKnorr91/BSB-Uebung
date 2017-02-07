#include "./domain.h"
#include "user/debug.h"
#include "./invaders.h"

Domain::Domain() {}

void Domain::addEntity(Entity* entity) {
    entityList.enqueue(entity);
}

void Domain::start() {
	player.fullReset();
	player.setPos(40,22);
    player.setDomain(this);
    addEntity(&player);

	score.fullReset();
    score.setPos(80-score.getHitbox()->getWidth(), 0);
    addEntity(&score);

    currentShotIndex = 0;
    currentMonsterIndex = 0;

    
    cooldown = 3*30;
	actCooldown = cooldown;
}

void Domain::update() {
	if (!player.isAlive()) {
		appInv.gameOver.setScore(score.getScore());
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
        for (int i=0; i <= monstercounter; i++ ){
        if (monsterBlue[i].isDead()){
            currentMonsterPointer = (Monster*) &monsterBlue[i];
            currentMonsterPointer->setLife(5);
            break;
        }

        }
    }
    else if(type == MonsterType::green)  {
        for (int i=0; i <= monstercounter;i++ ){
        if (monsterGreen[i].isDead()){
            currentMonsterPointer = (Monster*) &monsterGreen[i];
            currentMonsterPointer->setLife(3);
            break;
        }

    }
    }
    else if(type == MonsterType::red)  {
        for (int i=0; i <= monstercounter;i++ ){
        if (monsterRed[i].isDead()){
            currentMonsterPointer = (Monster*) &monsterRed[i];
            currentMonsterPointer->setLife(3);
            break;
        }

        }
    }

	currentMonsterPointer->fullReset();
    currentMonsterPointer->setPos(x,y);
    currentMonsterPointer->setDomain(this);
<<<<<<< 15696491157655aee87e4c02e2b9d19b83412f46
    monster[currentMonsterIndex] = currentMonsterPointer;
    currentMonsterIndex = (currentMonsterIndex+1)%60;
    addEntity(currentMonsterPointer);
=======
    

    for (int i=0; i <= monstercounter;i++ ){
        if (monster[i]->isDead()){
            monster[currentMonsterIndex] = currentMonsterPointer;
            addEntity(currentMonsterPointer);
            break;
        }

    }


   // addEntity(currentMonsterPointer);
>>>>>>> a002300c02d70243756e9b6e9846feb339f95d2a
}

void Domain::detectCollisions() {
    for(int i = 0; i < 3*monstercounter; i++) {
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
