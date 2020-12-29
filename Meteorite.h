#include "Sprite.h"
#ifndef CPROG_PROJEKT_METEORITE_H
#define CPROG_PROJEKT_METEORITE_H


class Meteorite : public Sprite {
public:
    void draw();
    bool tick();
    static Meteorite *getInstance(int x, int y, int w, int h);
    ~Meteorite();

private:
    SDL_Texture *meteoriteBMP;

protected:
    Meteorite(int x, int y, int w, int h);
};


#endif //CPROG_PROJEKT_METEORITE_H
