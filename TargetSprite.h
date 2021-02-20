#include "Sprite.h"
#ifndef CPROG_PROJEKT_METEORITE_H
#define CPROG_PROJEKT_METEORITE_H


class TargetSprite : public Sprite {
protected:
    TargetSprite(int x, int y, int w, int h, const char *path);

public:
    bool tick();
    static TargetSprite *getInstance();
    ~TargetSprite();
};


#endif //CPROG_PROJEKT_METEORITE_H
