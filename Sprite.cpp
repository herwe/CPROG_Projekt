#include "Sprite.h"
#include "System.h"

SDL_Rect &Sprite::get_rekt() {
    return rekt;
}

Sprite::Sprite(int x, int y, int w, int h, const char *path) : rekt{x, y, w, h} {
    SDL_Surface *image = SDL_LoadBMP(path);
    sdlTexture = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
    SDL_FreeSurface(image);
}

void Sprite::draw() {
    SDL_RenderCopy(sys.get_renderer(), sdlTexture, NULL, &get_rekt());
}


Sprite::~Sprite() {
    SDL_DestroyTexture(sdlTexture);
}

bool Sprite::collision(const Sprite *otherSprite) {
    if (this == otherSprite) {
        return false;
    }
    if (this->get_rekt().x < otherSprite->rekt.x && (this->get_rekt().x + this->get_rekt().w) > otherSprite->rekt.x) {
        if (this->get_rekt().y < otherSprite->rekt.y &&
            (this->get_rekt().y + this->get_rekt().h) > otherSprite->rekt.y){
            return true;
        }
    }
    return false;
}
