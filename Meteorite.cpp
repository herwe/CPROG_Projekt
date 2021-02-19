#define PATH "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/met.bmp"

#include "Meteorite.h"
#include <time.h> // Header needed to be included to generate random seed for srand().

Meteorite::Meteorite(int x, int y, int w, int h, const char* path = PATH) : Sprite(x, y, w, h, path) {}

Meteorite *Meteorite::getInstance() {
    //srand (time(nullptr)); //Sets seed for rng
    int x = rand() % 700 + 50;
    return new Meteorite(x, 0, 50, 50);
}

bool Meteorite::tick() {
    this->get_rekt().y += 3;

    if (this->get_rekt().y >= 600) {
        return true;
    }
    return false;
}
