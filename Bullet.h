
#include "Sprite.h"

#ifndef CPROG_PROJEKT_BULLET_H
#define CPROG_PROJEKT_BULLET_H


class Bullet : public Sprite {

protected:
    Bullet(int x, int y, int w, int h, const char *path);

public:
    bool tick();
    static Bullet *getInstance(int x, int y, int w, int h);
    ~Bullet();

};


#endif //CPROG_PROJEKT_BULLET_H
