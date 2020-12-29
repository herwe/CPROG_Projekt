
#include "Sprite.h"
#ifndef CPROG_PROJEKT_BULLET_H
#define CPROG_PROJEKT_BULLET_H


class Bullet : public Sprite {
public:
    void draw();
    bool tick();
    static Bullet *getInstance(int x, int y, int w, int h);
    ~Bullet();

private:
    SDL_Texture *bulletBMP;

protected:
    Bullet(int x, int y, int w, int h);
};




#endif //CPROG_PROJEKT_BULLET_H
