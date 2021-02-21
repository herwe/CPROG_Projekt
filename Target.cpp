#include "Target.h"
#include "GameEngine.h"
#include <time.h> // Header needed to be included to generate random seed for srand().

Target::Target(int x, int y, int w, int h, const char* path = engine.gameParams.targetSpritePath) : Sprite(x, y, w, h, path) {}

Target *Target::getInstance() {
    //srand (time(nullptr)); //Sets seed for rng
    int x = rand() % engine.gameParams.windowWidth + engine.gameParams.targetWidth;
    return new Target(x, 0, engine.gameParams.targetWidth, engine.gameParams.targetHeight);
}

bool Target::tick() {
    this->get_rekt().y += engine.gameParams.targetSpeed;

    if (this->get_rekt().y >= engine.gameParams.windowHeight) {
        return true;
    }
    return false;
}
