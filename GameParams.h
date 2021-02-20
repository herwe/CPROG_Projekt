//
// Created by fredr on 2021-02-20.
//

#ifndef CPROG_PROJEKT_GAMEPARAMS_H
#define CPROG_PROJEKT_GAMEPARAMS_H


#include <string>

using namespace std;

struct GameParams {
    //Starting position for the player sprite.
    int playerX;
    int playerY;

    //Player hitbox.
    int playerWidth;
    int playerHeight;

    //File paths for sprites.
    string backgroundSpritePath;
    string playerSpritePath;
    string targetSpritePath;
    string bulletSpritePath;

    //Window dimensions
    int windowWidth = 800;
    int windowHeight = 600;

};


#endif //CPROG_PROJEKT_GAMEPARAMS_H
