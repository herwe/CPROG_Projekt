//
// Created by fredr on 2021-02-20.
//

#ifndef CPROG_PROJEKT_GAMEPARAMS_H
#define CPROG_PROJEKT_GAMEPARAMS_H


#include <string>

using namespace std;

struct GameParams {
    //File paths for sprites.
    const char *backgroundSpritePath;
    const char *playerSpritePath;
    const char *targetSpritePath;
    const char *bulletSpritePath;

    //Window dimensions
    int windowWidth = 800;
    int windowHeight = 600;

    //Starting position for the player sprite.
    int playerX;
    int playerY;

    //Player hitbox.
    int playerWidth;
    int playerHeight;

    //Player speed in pixels per tick
    int playerSpeed;

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
