

#include "GameEngine.h"

void GameEngine::add(Sprite *sprite) {
    spriteList.push_back(sprite);
}

void GameEngine::run() {
    SDL_SetRenderDrawColor(sys.get_renderer(), 255, 255, 255, 255);

    SDL_RenderClear(sys.get_renderer());
    SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/space.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
    SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);
    for (Sprite* sprite : spriteList) {
        sprite->draw();
    }
    SDL_RenderPresent(sys.get_renderer());
    SDL_FreeSurface(image);
    //SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);
}

GameEngine::~GameEngine() {

}
