
#include <SDL2/SDL.h>
#include <string>
#include "Sprite.h"
#include "Bullet.h"
#include "Meteorite.h"

#ifndef CPROG_PROJEKT_SHIP_H
#define CPROG_PROJEKT_SHIP_H


class Ship : public Sprite {
private:
    SDL_Texture *shipBMP;
protected:
    Ship(int x, int y, int w, int h, const char *path);

public:
    static Ship *getInstance(int x, int y, int w, int h);
    void key_right();
    void key_left();
    Bullet* shoot();
    ~Ship();
};


#endif //CPROG_PROJEKT_SHIP_H
