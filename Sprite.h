
#include <SDL2/SDL.h>
#include "System.h"
#ifndef CPROG_PROJEKT_SPRITE_H
#define CPROG_PROJEKT_SPRITE_H


class Sprite {
private:
    SDL_Rect rekt;
    Sprite(const Sprite&) = delete;
    const Sprite& operator=(const Sprite&) = delete;
public:
    const SDL_Rect& get_rekt() const;
    virtual void key_right(const SDL_Event&);
    virtual void key_left(const SDL_Event&);
    virtual void draw() const = 0;
protected:
    Sprite(int x, int y, int w, int h);
};


#endif //CPROG_PROJEKT_SPRITE_H
