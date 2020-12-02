
#include <vector>
#include "Sprite.h"
#ifndef CPROG_PROJEKT_GAMEENGINE_H
#define CPROG_PROJEKT_GAMEENGINE_H


class GameEngine {
private:
    std::vector<Sprite*> spriteList;
public:
    ~GameEngine();
    void add(Sprite* sprite);
    void run();
};


#endif //CPROG_PROJEKT_GAMEENGINE_H
