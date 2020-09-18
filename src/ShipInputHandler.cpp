//
// Created by lavreniuk on 13.09.2020.
//

#include "ShipInputHandler.h"

void ShipInputHandler::handle(const Uint8 *state) {
    if (state[SDL_SCANCODE_UP]) {
        ship->push();
    }
    if (state[SDL_SCANCODE_LEFT]) {
        ship->rotate(-4.0f);
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        ship->rotate(4.0f);
    }
}

void ShipInputHandler::handle(SDL_Keycode keycode) {
    if(keycode == SDLK_DOWN){
        ship->slowDown();
    }
    if(keycode == SDLK_SPACE){
        auto bullet = ship->shoot();
        entitiesCollection->addEntity(bullet);
    }
}

ShipInputHandler::ShipInputHandler(Ship *ship, EntitiesCollection* entitiesCollection) {
    this->ship = ship;
    this->entitiesCollection = entitiesCollection;
}
