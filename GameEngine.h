#ifndef CPROG_PROJEKT_GameEngine_H
#define CPROG_PROJEKT_GameEngine_H

#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>
#include "Player.h"
#include "Sprite.h"
#include "Target.h"
#include "GameParams.h"

class GameEngine {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

    Player* player;
    std::vector<Sprite*> spriteList;
    std::vector<Sprite*> toRemoveList;
    Uint32 nextTick;
    int tickInterval;
    int delay;
    int targetSpawningDelay = 0;
    void removeCollidingSprites(Sprite *sprite);
    void targetSpawning();
    void executeRemove();

public:
    GameEngine();
    void addSprite(Sprite*);
    GameParams gameParams;
    ~GameEngine();
    void run(GameParams);
    void remove(Sprite *);
    SDL_Renderer* get_renderer() const;
};

extern GameEngine engine;

#endif //CPROG_PROJEKT_GameEngine_H
