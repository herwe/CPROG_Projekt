

#include "System.h"

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/space.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(5000);
}

System::~System() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_Quit();
}

SDL_Renderer *System::get_renderer() const {
    return renderer;
}

System sys;
