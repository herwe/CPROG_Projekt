#include "Sprite.h"
#ifndef CPROG_PROJEKT_METEORITE_H
#define CPROG_PROJEKT_METEORITE_H


class Target : public Sprite {
protected:
    Target(int x, int y, int w, int h, const char *path);

public:
    bool tick();
    static Target *getInstance();
};


#endif //CPROG_PROJEKT_METEORITE_H
