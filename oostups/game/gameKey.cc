#include "./gameKey.h"

Key* GameKey::getKey() {
    Key* tmpPointer = currentKeyPointer;
    currentKeyPointer = 0;
    return tmpPointer;
}

void GameKey::setKey(Key* key) {
    currentKeyPointer = key;
}

bool GameKey::hasKey() {
    return true;
    //return !!currentKeyPointer;
}