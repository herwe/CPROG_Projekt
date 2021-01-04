#include <SDL2/SDL.h>
#ifndef CPROG_PROJEKT_SYSTEM_H
#define CPROG_PROJEKT_SYSTEM_H


class System {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;

public:
    System();
    ~System();
    SDL_Renderer* get_renderer() const;
};

extern System sys;


#endif //CPROG_PROJEKT_SYSTEM_H
