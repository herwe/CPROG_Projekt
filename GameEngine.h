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
    Uint32 nextTick;
    int tickInterval;
    int delay;
    void collisionCheck(Sprite *sprite);
    void targetSpawning();
    void executeRemove();
public:
    void addSprite(Sprite*);
    GameParams gameParams;
    ~GameEngine();
    void run(GameParams);

    void remove(Sprite *);
};

extern GameEngine engine;

#endif //CPROG_PROJEKT_SpriteEngine_H
