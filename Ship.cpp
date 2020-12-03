

#include "Ship.h"

Ship::Ship(int x, int y, int w, int h) : Sprite(x,y,w,h) {

}

void Ship::draw() const {
    SDL_RenderCopy(sys.get_renderer(), shipBMP, NULL, &get_rekt());
}

Ship* Ship::getInstance(int x, int y, int w, int h) {
    return new Ship(x, y, w, h);
}

Ship::~Ship() {
    SDL_DestroyTexture(shipBMP);
}
