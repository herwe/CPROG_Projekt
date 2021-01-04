#include "Sprite.h"
#include <time.h>
#ifndef CPROG_PROJEKT_METEORITE_H
#define CPROG_PROJEKT_METEORITE_H


class Meteorite : public Sprite {
public:
    bool tick();
    static Meteorite *getInstance();
    ~Meteorite();

private:

protected:
    Meteorite(int x, int y, int w, int h, const char *path);
};


#endif //CPROG_PROJEKT_METEORITE_H
