#include "Target.h"
#include "GameEngine.h"

Target::Target(int x, int y, int w, int h, const char *path = engine.gameParams.targetSpritePath) : Sprite(x, y, w, h,
                                                                                                           path) {}

Target *Target::getInstance() {
    int x = rand() % engine.gameParams.windowWidth - engine.gameParams.targetWidth * 2;
    x += engine.gameParams.targetWidth;
    return new Target(x, 0, engine.gameParams.targetWidth, engine.gameParams.targetHeight);
}

void Target::tick() {
    this->get_rekt().y += engine.gameParams.targetSpeed;
    if (this->get_rekt().y >= engine.gameParams.windowHeight) {
        engine.remove(this);
    }
}
