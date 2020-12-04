

#include "GameEngine.h"

void GameEngine::add(Sprite *sprite) {
    spriteList.push_back(sprite);
}

void GameEngine::run() {
    bool quit = false;
    while (!quit) {
        SDL_Event eve;
        while (SDL_PollEvent(&eve)) {
            switch (eve.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (eve.key.keysym.sym) {
                        case SDLK_LEFT:
                            for (Sprite *c : spriteList)
                                c->key_left(eve);
                            break;
                        case SDLK_RIGHT:
                            for (Sprite *c : spriteList)
                                c->key_right(eve);
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    break;

            } // switch
        } // inre while
        SDL_SetRenderDrawColor(sys.get_renderer(), 255, 255, 255, 255);

        SDL_RenderClear(sys.get_renderer());
        SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/space.bmp");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
        SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);

        for (Sprite *sprite : spriteList) {
            sprite->draw();
        }

        SDL_RenderPresent(sys.get_renderer());
        SDL_FreeSurface(image);
        SDL_DestroyTexture(texture);

    } //yttre while


   /* SDL_SetRenderDrawColor(sys.get_renderer(), 255, 255, 255, 255);

    SDL_RenderClear(sys.get_renderer());
    SDL_Surface *image = SDL_LoadBMP("/home/herman/Dropbox/Termin 3/CPROG/Projekt/CPROG_Projekt/pics/space.bmp");
    SDL_Texture *texture = SDL_CreateTextureFromSurface(sys.get_renderer(), image);
    SDL_RenderCopy(sys.get_renderer(), texture, NULL, NULL);
    for (Sprite *sprite : spriteList) {
        sprite->draw();
    }

    SDL_RenderPresent(sys.get_renderer());
    SDL_FreeSurface(image);
    SDL_Delay(5000);
    */
}

GameEngine::~GameEngine() {

}
