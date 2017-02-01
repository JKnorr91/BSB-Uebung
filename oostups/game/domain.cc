#include "./domain.h"
#include "user/debug.h"

Domain::Domain() {
    player.setPos(40,22);
    player.setDomain(this);
    addEntity(&player);

    // monster.setPos(40,3);
    // monster.setDomain(this);
    // addEntity(&monster);

    // monster2.setPos(5,1);
    // monster2.setDomain(this);
    // addEntity(&monster2);



    createMonster(MonsterType::blue,40,3);
    createMonster(MonsterType::green,20,3);
    createMonster(MonsterType::blue,60,3);



    currentShotIndex = 0;
    currentMonsterIndex = 0;

    currentMonsterBlueIndex = 0;
    currentMonsterGreenIndex = 0;
    currentMonsterRedIndex = 0;
}

void Domain::addEntity(Entity* entity) {
    entityList.enqueue(entity);
}

void Domain::update() {
    Entity* currentEntity = (Entity*) entityList.first();
    while(currentEntity) {
        Entity* next = (Entity*) currentEntity->next;

        if (!(currentEntity->update())) {
            entityList.remove(currentEntity);
        }
        currentEntity = next;
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
    currentShot->setPos(x,y);
    addEntity(currentShot);
    currentShotIndex = (currentShotIndex+1) % 25;
}

void Domain::createMonster(unsigned char type, int x, int y) {
    
    Monster* currentMonsterPointer;

    if(type == MonsterType::blue) {
        currentMonsterPointer = (Monster*) &monsterBlue[currentMonsterBlueIndex];
        currentMonsterBlueIndex = (currentMonsterBlueIndex+1)%20;
    }
    else if(type == MonsterType::green)  {
        currentMonsterPointer = (Monster*) &monsterGreen[currentMonsterGreenIndex];
        currentMonsterGreenIndex = (currentMonsterGreenIndex+1)%20;
    }

    currentMonsterPointer->setPos(x,y);
    currentMonsterPointer->setDomain(this);
    monster[currentMonsterIndex] = currentMonsterPointer;
    currentMonsterIndex = (currentMonsterIndex+1)%60;
    addEntity(currentMonsterPointer);
}