#include "GameEngine.h"

GameEngine engine;


void GameEngine::addSprite(Sprite *sprite) {
    spriteList.push_back(sprite);
}

void GameEngine::remove(Sprite *sprite) {
    toRemoveList.push_back(sprite);
}

void GameEngine::run(GameParams gp) {
    gameParams = gp;

    tickInterval = 1000 / gameParams.fps;

    player = Player::getInstance(gameParams.playerX, gameParams.playerY, gameParams.playerWidth,
                                 gameParams.playerHeight);
    spriteList.push_back(player);

    bool quit = false;
    while (!quit) {
        nextTick = SDL_GetTicks() + tickInterval;
        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            if (eve.type == SDL_QUIT) {
                quit = true;
            }
            if (eve.type == SDL_KEYDOWN) {
                player->key_pressed(eve);
            }
        }

        //Runs the game at a constant speed
        delay = nextTick - SDL_GetTicks();
        if (delay > 0) {
            SDL_Delay(delay);
        }

        SDL_RenderClear(get_renderer());

        //Background image
        SDL_Surface *image = SDL_LoadBMP(gameParams.backgroundSpritePath);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(get_renderer(), image);
        SDL_RenderCopy(get_renderer(), texture, NULL, NULL);
        for (Sprite *sprite : spriteList) {
            removeCollidingSprites(sprite); //Marks colliding sprites for removal.
            sprite->tick();
            sprite->draw();         //Draws all sprites
        }

        targetSpawning();           //Handles target spawning, see method comment comment
        executeRemove();            //Removes all sprites in toRemoveList from spriteList

        SDL_RenderPresent(get_renderer());
        SDL_FreeSurface(image);
        SDL_DestroyTexture(texture);
    }
}

/*
 * Removes all sprites marked for removal.
 */
void GameEngine::executeRemove() {
    for (Sprite *rem : toRemoveList) {
        delete rem;
        spriteList.erase(find(spriteList.begin(), spriteList.end(), rem));
    }
    toRemoveList.clear();
}

/*
 * Spawns a target every targetFrequency:th tick.
 */
void GameEngine::targetSpawning() {
    if (targetSpawningDelay == 0){
        Target *temp = Target::getInstance();
        spriteList.push_back(temp);
        targetSpawningDelay = gameParams.targetFrequency;
    }else{
        targetSpawningDelay--;
    }
}

/*
 * Marks colliding sprites for removal.
 */
void GameEngine::removeCollidingSprites(Sprite *sprite) {
    for (Sprite *other : spriteList) {
        if (sprite->collision(other)) {
            toRemoveList.push_back(sprite);
            toRemoveList.push_back(other);
        }
    }
}


GameEngine::~GameEngine() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}

GameEngine::GameEngine() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(" Space Shooter", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, gameParams.windowWidth, gameParams.windowHeight, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

SDL_Renderer *GameEngine::get_renderer() const {
    return renderer;
}
