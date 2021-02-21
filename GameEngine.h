#ifndef CPROG_PROJEKT_SpriteEngine_H
#define CPROG_PROJEKT_SpriteEngine_H


#include <vector>
#include <algorithm>
#include "Player.h"
#include "Sprite.h"
#include "Target.h"
#include "GameParams.h"

class GameEngine {
private:

    Player* player;
    std::vector<Sprite*> spriteList;
    std::vector<Sprite*> toRemoveList;
    std::vector<Target*> targetList;
    bool bulletOnScreen = false;
    Uint32 nextTick;
    int tickInterval;
    int delay;
    bool existShip = true;

    void bulletCheck(Sprite *sprite);
    Sprite* collisionCheck(Sprite *sprite);
    void targetSpawning();
    void targetDeletion();
    void remove();
    void addSprite(Sprite*);

public:
    GameParams gameParams;
    ~GameEngine();
    void run(GameParams);

};

extern GameEngine g_engine;

#endif //CPROG_PROJEKT_SpriteEngine_H
