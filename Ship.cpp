

#include "Ship.h"

Ship::Ship(int x, int y, int w, int h) : Sprite(x,y,w,h) {
    SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/ship.bmp");
    shipBMP = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
    SDL_FreeSurface(image);
}

void Ship::draw() const {
    SDL_RenderCopy(sys.get_renderer(), shipBMP, NULL, &get_rekt());
}

Ship* Ship::getInstance(int x, int y, int w, int h) {
    return new Ship(x, y, w, h);
}

Ship::~Ship() {
    SDL_DestroyTexture(shipBMP);
}
