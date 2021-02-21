
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Bullet.h"

#ifndef CPROG_PROJEKT_PLAYER_H
#define CPROG_PROJEKT_PLAYER_H


class Player : public Sprite {
private:
    int bulletDelay = 0;
protected:
    Player(int x, int y, int w, int h, const char *path);

public:
    void tick();
    static Player *getInstance(int x, int y, int w, int h);
    Bullet* shoot();
    void key_pressed(SDL_Event e);
};


#endif //CPROG_PROJEKT_PLAYER_H
