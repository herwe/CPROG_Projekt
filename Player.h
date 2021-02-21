
#include <SDL2/SDL.h>
#include <string>
#include "Sprite.h"
#include "Bullet.h"
#include "Target.h"

#ifndef CPROG_PROJEKT_SHIP_H
#define CPROG_PROJEKT_SHIP_H


class Player : public Sprite {
protected:
    Player(int x, int y, int w, int h, const char *path);

public:
    static Player *getInstance(int x, int y, int w, int h);
    void key_right();
    void key_left();
    Bullet* shoot();
    void key_pressed(SDL_Event e);
};


#endif //CPROG_PROJEKT_SHIP_H
