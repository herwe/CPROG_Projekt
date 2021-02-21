#include "Sprite.h"
#ifndef CPROG_PROJEKT_TARGET_H
#define CPROG_PROJEKT_TARGET_H


class Target : public Sprite {
protected:
    Target(int x, int y, int w, int h, const char *path);

public:
    void tick();
    static Target *getInstance();
};


#endif //CPROG_PROJEKT_TARGET_H
