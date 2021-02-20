#ifndef CPROG_PROJEKT_SpriteEngine_H
#define CPROG_PROJEKT_SpriteEngine_H
#define FPS 60

#include <vector>
#include <algorithm>
#include "Player.h"
#include "Sprite.h"
#include "TargetSprite.h"
#include "GameParams.h"

class SpriteEngine {
private:
    Player* player;
    std::vector<Sprite*> spriteList;
    std::vector<Sprite*> toRemoveList;
    std::vector<TargetSprite*> targetList;
    bool bulletOnScreen = false;
    const int tickInterval = 1000 / FPS;
    Uint32 nextTick;
    int delay;
    bool existShip = true;

    void bulletCheck(Sprite *sprite);
    Sprite* collisionCheck(Sprite *sprite);
    void targetSpawning();
    void targetDeletion();
    void remove();
    void addSprite(Sprite*);

public:
    ~SpriteEngine();
    void run(GameParams);

};

extern SpriteEngine engine;

#endif //CPROG_PROJEKT_SpriteEngine_H
