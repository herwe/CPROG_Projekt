
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Bullet.h"
#include "Meteorite.h"

#ifndef CPROG_PROJEKT_SHIP_H
#define CPROG_PROJEKT_SHIP_H


class Ship : public Sprite {
private:
    SDL_Texture *shipBMP;
protected:
    Ship(int x, int y, int w, int h);

public:
    static Ship *getInstance(int x, int y, int w, int h);
    void key_right(const SDL_Event &);
    void key_left(const SDL_Event &);
    void draw();
    Bullet* shoot();
    Meteorite* spawnMeteorite();
    ~Ship();
};


#endif //CPROG_PROJEKT_SHIP_H
