#include "Bullet.h"
#include "GameEngine.h"

Bullet::Bullet(int x, int y, int w, int h, const char* path = engine.gameParams.bulletSpritePath) : Sprite(x, y, w, h, path) {}

void Bullet::tick() {
    this->get_rekt().y -= engine.gameParams.bulletSpeed;

    if (this->get_rekt().y <= 0) {
        engine.remove(this);
    }
}

Bullet *Bullet::getInstance(int x, int y) {
    return new Bullet(x, y, engine.gameParams.bulletWidth, engine.gameParams.bulletHeight);
}




