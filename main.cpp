#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"




int main() {
    SDL_Window* window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Surface* image = SDL_LoadBMP("/home/herman/Documents/space.bmp");
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);
    SDL_Texture* texture1 = SDL_CreateTextureFromSurface(render, image);

    SDL_RenderCopy(render, texture1, NULL, NULL);
    SDL_RenderPresent(render);

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    SDL_DestroyTexture(texture1);
    SDL_DestroyRenderer(render);
    SDL_FreeSurface(image);
    SDL_DestroyWindow(window);

    SDL_Quit();


}


