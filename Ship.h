
#include <SDL2/SDL.h>
#include "Sprite.h"
#ifndef CPROG_PROJEKT_SHIP_H
#define CPROG_PROJEKT_SHIP_H


class Ship : Sprite {
private:
    SDL_Texture* shipBMP;
protected:
    Ship(int x, int y, int w, int h);
public:
    static Ship* getInstance(int x, int y, int w, int h);
    void draw() const;
    ~Ship();
};


#endif //CPROG_PROJEKT_SHIP_H
