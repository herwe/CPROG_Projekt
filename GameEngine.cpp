#include <iostream>
#include "Bullet.h"
#include "GameEngine.h"
#include "Player.h"

GameEngine engine;

void GameEngine::addSprite(Sprite* sprite){
    spriteList.push_back(sprite);
}

void GameEngine::remove(Sprite* sprite){
    toRemoveList.push_back(sprite);
}

void GameEngine::run(GameParams gp) {
    gameParams = gp;

    tickInterval = 1000 / gameParams.fps;

    player = Player::getInstance(gameParams.playerX, gameParams.playerY, gameParams.playerWidth, gameParams.playerHeight);
    spriteList.push_back(player);
    bool quit = false;
    while (!quit) {
        nextTick = SDL_GetTicks() + tickInterval;
        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            if (eve.type == SDL_QUIT){
                quit = true;
            }
            if (eve.type == SDL_KEYDOWN){
                player->key_pressed(eve);
            }
        }

        //Runs the game at a constant speed
        delay = nextTick - SDL_GetTicks();
        if (delay > 0) {
            SDL_Delay(delay);
        }

        SDL_RenderClear(sys.get_renderer());

        //Background image
        SDL_Surface *image = SDL_LoadBMP(gameParams.backgroundSpritePath);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
        SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);
        for (Sprite *sprite : spriteList) {
            collisionCheck(sprite); //Handles sprite collision
            sprite->tick();
            sprite->draw();         //Draws all sprites
        }

        targetSpawning();           //Handles target spawning, see method comment comment
        executeRemove();            //Removes all sprites in toRemoveList from spriteList

        SDL_RenderPresent(sys.get_renderer());
        SDL_FreeSurface(image);
        SDL_DestroyTexture(texture);


    }
}

/*
 * Removes all sprites marked for removal from spriteList
 */
void GameEngine::executeRemove() {
    for (Sprite *rem : toRemoveList) {
        bool isTarget = dynamic_cast<Target*>(rem);
        delete rem;
        spriteList.erase(find(spriteList.begin(), spriteList.end(), rem));
        if (isTarget){
            targetList.erase(find(targetList.begin(), targetList.end(), rem));
        }
    }
    toRemoveList.clear();
}

/*
 * Spawns target if
 * there are no targets
 * OR
 * if there is only one target on screen and it has reached at least halfway down
 */
void GameEngine::targetSpawning() {
    if (targetList.empty() || (targetList.size() < 2 && targetList[0]->get_rekt().y > 300)) {
        Target *temp = Target::getInstance();
        targetList.push_back(temp);
        spriteList.push_back(temp);
    }
}

/*
 * Checks collisions
 */

void GameEngine::collisionCheck(Sprite *sprite) {
    for (Sprite *other : spriteList) {
        if (sprite->collision(other)) {
            toRemoveList.push_back(sprite);
            toRemoveList.push_back(other);
        }
    }
}


GameEngine::~GameEngine() {

}
