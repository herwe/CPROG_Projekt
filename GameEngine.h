
#include <vector>
#include "Sprite.h"
#include "Meteorite.h"
#ifndef CPROG_PROJEKT_GAMEENGINE_H
#define CPROG_PROJEKT_GAMEENGINE_H
#define FPS 60


class GameEngine {
private:
    std::vector<Sprite*> spriteList;
    std::vector<Sprite*> removedList;
    std::vector<Meteorite*> metList;
    bool bullet_on_screen;
    const int tickInterval = 1000 / FPS;
    Uint32 nextTick;
    int delay;
public:
    ~GameEngine();
    void add(Sprite* sprite);
    void run();
    void remove(Sprite* sprite);
};


#endif //CPROG_PROJEKT_GAMEENGINE_H
