#define PATH "/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/ship.bmp"

#include "Ship.h"

Ship::Ship(int x, int y, int w , int h, const char *path = PATH) : Sprite(x, y, w, h, path) {

}

void Ship::key_left() {
    if (this->get_rekt().x > 0){
        this->get_rekt().x -= 5;
    }
}

void Ship::key_right() {
    if (this->get_rekt().x < 700){
        this->get_rekt().x += 5;
    }
}


Ship* Ship::getInstance(int x, int y, int w, int h) {
    return new Ship(x, y, w, h);
}


Bullet* Ship::shoot() {
    Bullet* b = Bullet::getInstance(this->get_rekt().x + 38, this->get_rekt().y - 30, 25,50);
    return b;
}

