#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "GameEngine.h"
#include "Ship.h"




int main(int argc, char *argv[]) {

    GameEngine gameEngine;
    Ship* ship = Ship::getInstance(350,550,100,50);
    gameEngine.add(ship);
    gameEngine.run();


    return 0;



}


