#define PATH "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/ship.bmp"

#include "Ship.h"

Ship::Ship(int x, int y, int w , int h, const char *path = PATH) : Sprite(x, y, w, h, path) {}

void Ship::key_pressed(SDL_Event eve){
    switch (eve.key.keysym.sym) {
        case SDLK_LEFT:
            if (this->get_rekt().x > 0){
                this->get_rekt().x -= 5;
            }
            break;
        case SDLK_RIGHT:
            if (this->get_rekt().x < 700){
                this->get_rekt().x += 5;
            }
            break;
        case SDLK_SPACE:

            break;

//        case SDLK_SPACE:    //If the player presses space and there is no bullet on screen AND there exists a ship, shoot and disable the ability to shoot
//
//                if (!bulletOnScreen && existShip) {
//                spriteList.push_back(ship->shoot());
//                bulletOnScreen = true;
//            }
    }
}

Ship* Ship::getInstance(int x, int y, int w, int h) {
    return new Ship(x, y, w, h);
}


Bullet* Ship::shoot() {
    Bullet* b = Bullet::getInstance(this->get_rekt().x + 38, this->get_rekt().y - 30, 25,50);
    return b;
}




