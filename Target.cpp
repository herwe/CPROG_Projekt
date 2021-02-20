#define PATH "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/met.bmp"

#include "Target.h"
#include <time.h> // Header needed to be included to generate random seed for srand().

Target::Target(int x, int y, int w, int h, const char* path = PATH) : Sprite(x, y, w, h, path) {}

Target *Target::getInstance() {
    //srand (time(nullptr)); //Sets seed for rng
    int x = rand() % 700 + 50;
    return new Target(x, 0, 50, 50);
}

bool Target::tick() {
    this->get_rekt().y += 3;

    if (this->get_rekt().y >= 600) {
        return true;
    }
    return false;
}
