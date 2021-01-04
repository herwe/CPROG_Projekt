#define PATH "/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/space.bmp"

#include <iostream>
#include "Bullet.h"
#include "GameEngine.h"
#include "Ship.h"

void GameEngine::run() {

    ship = Ship::getInstance(350, 550, 100, 50);
    spriteList.push_back(ship);
    bool quit = false;
    while (!quit) {
        nextTick = SDL_GetTicks() + tickInterval;
        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            switch (eve.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (eve.key.keysym.sym) {
                        case SDLK_LEFT:
                            ship->key_left();
                            break;
                        case SDLK_RIGHT:
                            ship->key_right();
                            break;
                        case SDLK_SPACE:    //If the player presses space and there is no bullet on screen, shoot and disable the ability to shoot
                            if (!bulletOnScreen) {
                                spriteList.push_back(ship->shoot());
                                bulletOnScreen = true;
                            }
                    }
                    break;
                case SDL_KEYUP:
                    break;

            }
        }

        //Run the game at a constant speed
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

        meteoriteSpawning();        //Handles meteorite spawning, see method comment comment
        meteoriteDeletion();        //If a meteorite leaves the screen, delete it

        remove();                   //Removes all sprites in toRemoveList from spriteList

        SDL_RenderPresent(sys.get_renderer());
        SDL_FreeSurface(image);
        SDL_DestroyTexture(texture);


    }
}

/*
 * Removes all sprites marked for removal from spriteList
 */
void GameEngine::remove() {
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
void GameEngine::meteoriteDeletion() {
    bool deleteFirstMeteorite = false;
    for (Meteorite *meteorite : meteoriteList) {
        if (meteorite->tick()) {
            toRemoveList.push_back(meteorite);
            deleteFirstMeteorite = true;
        }
    }

    if (deleteFirstMeteorite) {
        meteoriteList.erase(meteoriteList.begin());
    }
}

/*
 * Spawns meteorites if
 * there are no meteorites
 * OR
 * if there is only one meteorite on screen and it has reached at least halfway down
 */
void GameEngine::meteoriteSpawning() {
    if (meteoriteList.empty() || (meteoriteList.size() < 2 && meteoriteList[0]->get_rekt().y > 300)) {
        Meteorite *temp = Meteorite::getInstance();
        meteoriteList.push_back(temp);
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
            if (dynamic_cast<Ship*>(sprite) || dynamic_cast<Ship*>(other)) { // Game over!
                bulletOnScreen = true;
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
void GameEngine::bulletCheck(Sprite *sprite) {
    if (Bullet *b = dynamic_cast<Bullet *>(sprite)) {
        if (b->tick()) {
            bulletOnScreen = false;
            toRemoveList.push_back(b);
        }
    }
}


GameEngine::~GameEngine() {

}
