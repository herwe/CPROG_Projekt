

#include <iostream>
#include "Sprite.h"

SDL_Rect &Sprite::get_rekt() {
    return rekt;
}

Sprite::Sprite(int x, int y, int w, int h) : rekt{x, y, w, h} {

}

void Sprite::key_right(const SDL_Event &) {

}


void Sprite::key_left(const SDL_Event &) {

}

Sprite::~Sprite() {
    std::cout << "borta" << std::endl;
}
