#include "./domain.h"

Domain::Domain() {
    player.setPos(40,22);
    addEntity(&player);
}

void Domain::addEntity(Entity* entity) {
    entityList.enqueue(entity);
}

void Domain::update(GameKey* key) {
    Key* pressedKey = key->getKey();
    Entity* currentEntity = (Entity*) entityList.first();
    while(currentEntity) {
        Entity* next = (Entity*) currentEntity->next;

        if (!(currentEntity->update(pressedKey))) {
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
    shot.setPos(x,y);
    addEntity(&shot);
}