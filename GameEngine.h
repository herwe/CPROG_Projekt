#ifndef CPROG_PROJEKT_GAMEENGINE_H
#define CPROG_PROJEKT_GAMEENGINE_H
#define FPS 60

#include <vector>
#include "Ship.h"
#include "Sprite.h"
#include "Meteorite.h"


class GameEngine {
private:
    Ship* ship;
    std::vector<Sprite*> spriteList;
    std::vector<Sprite*> toRemoveList;
    std::vector<Meteorite*> meteoriteList;
    bool bulletOnScreen = false;
    const int tickInterval = 1000 / FPS;
    Uint32 nextTick;
    int delay;
public:
    ~GameEngine();
    void run();

    void bulletCheck(Sprite *sprite);

    void collisionCheck(Sprite *sprite);

    void meteoriteSpawning();

    void meteoriteDeletion();

    void remove();
};


#endif //CPROG_PROJEKT_GAMEENGINE_H
