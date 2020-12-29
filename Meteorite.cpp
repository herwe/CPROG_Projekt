#include "Meteorite.h"

Meteorite::Meteorite(int x, int y, int w, int h) : Sprite(x, y, w, h) {
    SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/met.bmp");
    meteoriteBMP = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
    SDL_FreeSurface(image);
}

void Meteorite::draw() {
    SDL_RenderCopy(sys.get_renderer(), meteoriteBMP, NULL, &get_rekt());
}


Meteorite *Meteorite::getInstance(int x, int y, int w, int h) {
    return new Meteorite(x, y, w, h);
}

bool Meteorite::tick() {
    this->get_rekt().y += 10;
    if (this->get_rekt().y <= 600) {
        return true;
    }

    return false;
}
