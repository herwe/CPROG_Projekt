
#include <vector>
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(int x, int y, int w, int h) : Sprite(x, y, w, h) {
    SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/bullet.bmp");
    bulletBMP = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
    SDL_FreeSurface(image);
}

void Bullet::draw() {
    SDL_RenderCopy(sys.get_renderer(), bulletBMP, NULL, &get_rekt());
}

bool Bullet::tick() {
    this->get_rekt().y -= 10;

    if (this->get_rekt().y <= 0) {
        return true;
    }

    return false;

}

Bullet *Bullet::getInstance(int x, int y, int w, int h) {
    return new Bullet(x, y, w, h);
}

Bullet::~Bullet() {
    SDL_DestroyTexture(bulletBMP);
}


