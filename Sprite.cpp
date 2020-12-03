

#include <iostream>
#include "Sprite.h"

const SDL_Rect& Sprite::get_rekt() const {
    return rekt;
}

Sprite::Sprite(int x, int y, int w, int h) : rekt{x,y,w,h} {

}

void Sprite::key_right(const SDL_Event &) {

}


void Sprite::key_left(const SDL_Event &) {

}
