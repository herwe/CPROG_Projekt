#define PATH "/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/bullet.bmp"
#include <vector>
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(int x, int y, int w, int h, const char* path = PATH) : Sprite(x, y, w, h, path) {

}


bool Bullet::tick() {
    this->get_rekt().y -= 15;

    if (this->get_rekt().y <= 0) {
        return true;
    }

    return false;

}

Bullet *Bullet::getInstance(int x, int y, int w, int h) {
    return new Bullet(x, y, w, h);
}




