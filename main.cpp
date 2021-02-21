#include "Sprite.h"
#include "GameEngine.h"
#include "Player.h"
#include "Target.h"


int main(int argc, char *argv[]) {
    GameParams gameParams;

    gameParams.backgroundSpritePath = "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/space.bmp";
    gameParams.playerSpritePath = "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/ship.bmp";
    gameParams.bulletSpritePath = "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/bullet.bmp";
    gameParams.targetSpritePath = "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/met.bmp";

    gameParams.playerX = 350;
    gameParams.playerY = 550;
    gameParams.playerWidth = 100;
    gameParams.playerHeight = 50;

    gameParams.targetWidth = 50;
    gameParams.targetHeight = 50;
    gameParams.targetSpeed = 3;

    gameParams.bulletWidth = 25;
    gameParams.bulletHeight = 50;
    gameParams.bulletOffsetX = 38;
    gameParams.bulletOffsetY = -30;
    gameParams.bulletSpeed = 15;

    g_engine.run(gameParams);
    return 0;
}
