

#include "Ship.h"

Ship::Ship(int x, int y, int w, int h) : Sprite(x,y,w,h) {
    SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/ship.bmp");
    shipBMP = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
    SDL_FreeSurface(image);
}

void Ship::draw()  {
    SDL_RenderCopy(sys.get_renderer(), shipBMP, NULL, &get_rekt());
}

void Ship::key_left(const SDL_Event &) {
    this->get_rekt().x -= 5;
}

void Ship::key_right(const SDL_Event &) {
    this->get_rekt().x += 5;
}


Ship* Ship::getInstance(int x, int y, int w, int h) {
    return new Ship(x, y, w, h);
}

Ship::~Ship() {
    SDL_DestroyTexture(shipBMP);
}

Bullet* Ship::shoot() {
    Bullet* b = Bullet::getInstance(this->get_rekt().x, this->get_rekt().y, 50,50);
    return b;
}

