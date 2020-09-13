//
// Created by lavreniuk on 13.09.2020.
//

#ifndef ASTEROIDS_SHIPINPUTHANDLER_H
#define ASTEROIDS_SHIPINPUTHANDLER_H


#include "Ship.h"
#include "EntitiesCollection.h"

class ShipInputHandler {
private:
    Ship* ship;
    EntitiesCollection* entitiesCollection;
public:
    ShipInputHandler(Ship* ship, EntitiesCollection* entitiesCollection);
    void handle(const Uint8* state);
    void handle(SDL_Keycode keycode);
};


#endif //ASTEROIDS_SHIPINPUTHANDLER_H
