
#include <iostream>
#include "Bullet.h"
#include "GameEngine.h"
#include "Ship.h"

void GameEngine::add(Sprite *sprite) {
    spriteList.push_back(sprite);
}

void GameEngine::remove(Sprite* sprite) {
    removedList.push_back(sprite);
}



void GameEngine::run() {
    bool quit = false;
    while (!quit) {
        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            switch (eve.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (eve.key.keysym.sym) {
                        case SDLK_LEFT:
                            for (Sprite *c : spriteList)
                                c->key_left(eve);
                            break;
                        case SDLK_RIGHT:
                            for (Sprite *c : spriteList)
                                c->key_right(eve);
                            break;
                        case SDLK_SPACE:
                            for (Sprite *c : spriteList) {
                                if (Ship* ship = dynamic_cast<Ship*>(c)) {
                                    if (!bullet_on_screen) {
                                        spriteList.push_back(ship->shoot());
                                        bullet_on_screen = true;
                                    }
                                }
                            }
                    }
                    break;
                case SDL_KEYUP:
                    break;

            } // switch
        } // inre while
        SDL_SetRenderDrawColor(sys.get_renderer(), 255, 255, 255, 255);

        SDL_RenderClear(sys.get_renderer());
        SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/space.bmp");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
        SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);

        for (Sprite *sprite : spriteList) {
            if (Bullet* b = dynamic_cast<Bullet*>(sprite)) {
                if (b->tick()) {
                    bullet_on_screen = false;
                    removedList.push_back(b);
                }
            }
            sprite->draw();
        }

        for (Sprite* spriteL : removedList) {
            for (std::vector<Sprite*>::iterator i = spriteList.begin(); i!= spriteList.end();) {
                if (*i == spriteL) {
                    i = spriteList.erase(i);
                } else {
                    i++;
                }
            }
        }
        removedList.clear();

        SDL_RenderPresent(sys.get_renderer());
        SDL_FreeSurface(image);
        SDL_DestroyTexture(texture);


    } //yttre while


   /* SDL_SetRenderDrawColor(sys.get_renderer(), 255, 255, 255, 255);

    SDL_RenderClear(sys.get_renderer());
    SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/space.bmp");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
    SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);
    for (Sprite *sprite : spriteList) {
        sprite->draw();
    }

    SDL_RenderPresent(sys.get_renderer());
    SDL_FreeSurface(image);
    SDL_Delay(5000);
    */
}

GameEngine::~GameEngine() {

}
