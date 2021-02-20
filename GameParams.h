//
// Created by fredr on 2021-02-20.
//

#ifndef CPROG_PROJEKT_GAMEPARAMS_H
#define CPROG_PROJEKT_GAMEPARAMS_H


#include <string>

using namespace std;

struct GameParams {
    //File paths for sprites.
    string backgroundSpritePath;
    string playerSpritePath;
    string targetSpritePath;
    string bulletSpritePath;

    //Window dimensions
    int windowWidth = 800;
    int windowHeight = 600;

    //Starting position for the player sprite.
    int playerX;
    int playerY;

    //Player hitbox.
    int playerWidth;
    int playerHeight;

    //Target hitbox.
    int targetWidth;
    int targetHeight;

    //Number of pixels to drop per tick.
    int targetSpeed;

    //Bullet hitbox.
    int bulletWidth;
    int bulletHeight;

    //Number of pixels to move up per tick.
    int bulletSpeed;

    //Bullet offset from player when bullets are spawned.
    int bulletOffsetX;
    int bulletOffsetY;

    int fps = 60;

};


#endif //CPROG_PROJEKT_GAMEPARAMS_H
