#include <SDL2/SDL.h>

#ifndef CPROG_PROJEKT_SPRITE_H
#define CPROG_PROJEKT_SPRITE_H


class Sprite {
private:
    SDL_Rect rekt;
    Sprite(const Sprite &) = delete;
    const Sprite &operator=(const Sprite &) = delete;
    SDL_Texture *sdlTexture;

protected:
    Sprite(int x, int y, int w, int h, const char *path);

public:
    virtual void tick(){};
    virtual ~Sprite();
    SDL_Rect &get_rekt();
    virtual void draw();
    bool collision(const Sprite *);
};


#endif //CPROG_PROJEKT_SPRITE_H
