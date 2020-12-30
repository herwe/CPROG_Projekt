

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

bool Sprite::collision(const Sprite* otherSprite) {
    if (this == otherSprite) {
        return false;
    }
    if (this->get_rekt().x < otherSprite->rekt.x && (this->get_rekt().x + this->get_rekt().w) > otherSprite->rekt.x) {
        if (this->get_rekt().y < otherSprite->rekt.y && (this->get_rekt().y + this->get_rekt().h) > otherSprite->rekt.y) {
            return true;
        }
    }
    return false;
}
