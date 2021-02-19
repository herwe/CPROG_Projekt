#ifndef CPROG_PROJEKT_GAMEENGINE_H
#define CPROG_PROJEKT_GAMEENGINE_H
#define FPS 60

#include <vector>
#include <algorithm>
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
    bool existShip = true;

    void bulletCheck(Sprite *sprite);
    Sprite* collisionCheck(Sprite *sprite);
    void meteoriteSpawning();
    void meteoriteDeletion();
    void remove();
    void addSprite(Sprite*);

public:
    ~GameEngine();
    void run();

};

extern GameEngine engine;

#endif //CPROG_PROJEKT_GAMEENGINE_H
