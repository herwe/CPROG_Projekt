#include "GameEngine.h"

int main(int argc, char *argv[]) {
    GameParams gameParams;

    gameParams.backgroundSpritePath = "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/space.bmp";
    gameParams.playerSpritePath = "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/ship.bmp";
    gameParams.bulletSpritePath = "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/bullet.bmp";
    gameParams.targetSpritePath = "E:/fredr/Documents/CLionProjects/CPROG Projekt/CPROG_Projekt/pics/met.bmp";

    gameParams.playerWidth = 100;
    gameParams.playerHeight = 50;
    gameParams.playerSpeed = 5;

    gameParams.targetWidth = 50;
    gameParams.targetHeight = 50;
    gameParams.targetSpeed = 3;

    gameParams.bulletWidth = 25;
    gameParams.bulletHeight = 50;
    gameParams.bulletSpeed = 15;
    gameParams.bulletDelay = 30;

    gameParams.initializePositionParams();

    engine.run(gameParams);
    return 0;
}
