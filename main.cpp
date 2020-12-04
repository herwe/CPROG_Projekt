#include <iostream>
#include <SDL2/SDL.h>
#include "Sprite.h"
#include "GameEngine.h"
#include "Ship.h"




int main(int argc, char *argv[]) {

    GameEngine gameEngine;
    Ship* ship = Ship::getInstance(200,50,350,250);
    gameEngine.add(ship);
    gameEngine.run();


    return 0;



}


