#ifndef __GameKey_include__
#define __GameKey_include__

#include "machine/key.h"

class GameKey {
    private:
        GameKey (const GameKey &copy); // Verhindere Kopieren
        Key* currentKeyPointer;
    public:
        GameKey() {};
        void setKey(Key* key);
        bool hasKey();
        Key* getKey();
};
extern GameKey gameKey;
#endif