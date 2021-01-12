#include "Sprite.h"
#ifndef CPROG_PROJEKT_METEORITE_H
#define CPROG_PROJEKT_METEORITE_H


class Meteorite : public Sprite {
protected:
    Meteorite(int x, int y, int w, int h, const char *path);

public:
    bool tick();
    static Meteorite *getInstance();
    ~Meteorite();
};


#endif //CPROG_PROJEKT_METEORITE_H
