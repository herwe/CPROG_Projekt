#define PATH "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/space.bmp"

#include <iostream>
#include "Bullet.h"
#include "SpriteEngine.h"
#include "Player.h"


void SpriteEngine::addSprite(Sprite* sprite){
    spriteList.push_back(sprite);
//BOOM
}

void SpriteEngine::run(GameParams gameParams) {

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
        SDL_Surface *image = SDL_LoadBMP(PATH);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
        SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);
        for (Sprite *sprite : spriteList) {
            bulletCheck(sprite);    //Handles bullets, see method comment comment
            collisionCheck(sprite); //Handles sprite collision
            sprite->draw();         //Draws all sprites
        }

        targetSpawning();        //Handles meteorite spawning, see method comment comment
        targetDeletion();        //If a meteorite leaves the screen, delete it

        remove();                   //Removes all sprites in toRemoveList from spriteList

        SDL_RenderPresent(sys.get_renderer());
        SDL_FreeSurface(image);
        SDL_DestroyTexture(texture);


    }
}

/*
 * Removes all sprites marked for removal from spriteList
 */
void SpriteEngine::remove() {
    for (Sprite *spriteL : toRemoveList) {
        for (std::vector<Sprite *>::iterator i = spriteList.begin(); i != spriteList.end();) {
            if (*i == spriteL) {
                i = spriteList.erase(i);
            } else {
                i++;
            }
        }
    }
    toRemoveList.clear();
}

/*
 * If a meteorite leaves the screen, delete it
 */
void SpriteEngine::targetDeletion() {
    bool deleteFirstMeteorite = false;
    for (TargetSprite *meteorite : targetList) {
        if (meteorite->tick()) {
            toRemoveList.push_back(meteorite);
            deleteFirstMeteorite = true;
        }
    }

    if (deleteFirstMeteorite) {
        targetList.erase(targetList.begin());
    }
}

/*
 * Spawns meteorites if
 * there are no meteorites
 * OR
 * if there is only one meteorite on screen and it has reached at least halfway down
 */
void SpriteEngine::targetSpawning() {
    if (targetList.empty() || (targetList.size() < 2 && targetList[0]->get_rekt().y > 300)) {
        TargetSprite *temp = TargetSprite::getInstance();
        targetList.push_back(temp);
        spriteList.push_back(temp);
    }
}

/*
 * Checks collisions
 */

Sprite* SpriteEngine::collisionCheck(Sprite *sprite) {
    for (Sprite *other : spriteList) {
        if (sprite->collision(other)) {
            toRemoveList.push_back(sprite);
            toRemoveList.push_back(other);
            if (dynamic_cast<Player*>(sprite) || dynamic_cast<Player*>(other)) { // Game over!
                existShip = false;
            } else {
                bulletOnScreen = false;
            }
        }
    }
}

/*
 * Checks if the bullet is outside the screen
 * and if so sets bulletOnScreen to false so that the player can shoot another shot
 * and adds the bullet to toRemoveList
 */
void SpriteEngine::bulletCheck(Sprite *sprite) {
    if (Bullet *b = dynamic_cast<Bullet *>(sprite)) {
        if (b->tick()) {
            bulletOnScreen = false;
            toRemoveList.push_back(b);
        }
    }
}


SpriteEngine::~SpriteEngine() {

}
