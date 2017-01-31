#include "./domain.h"
#include "user/debug.h"

Domain::Domain() {
    player.setPos(40,22);
    player.setDomain(this);
    addEntity(&player);

    currentShotIndex = 0;
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