

#include "System.h"

System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("   Space Invaders", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);


   //SDL_UpdateWindowSurface(window);

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
