#include <vector>
#include "Bullet.h"
#include "GameEngine.h"

Bullet::Bullet(int x, int y, int w, int h, const char* path = engine.gameParams.bulletSpritePath) : Sprite(x, y, w, h, path) {}

bool Bullet::tick() {
    this->get_rekt().y -= engine.gameParams.bulletSpeed;

    if (this->get_rekt().y <= 0) {
        return true;
    }
    return false;
}

Bullet *Bullet::getInstance(int x, int y, int w, int h) {
    return new Bullet(x, y, w, h);
}




