
#include <vector>
#include "Sprite.h"
#ifndef CPROG_PROJEKT_GAMEENGINE_H
#define CPROG_PROJEKT_GAMEENGINE_H


class GameEngine {
private:
    std::vector<Sprite*> spriteList;
    std::vector<Sprite*> removedList;
    bool bullet_on_screen;
public:
    ~GameEngine();
    void add(Sprite* sprite);
    void run();
    void remove(Sprite* sprite);
};


#endif //CPROG_PROJEKT_GAMEENGINE_H
