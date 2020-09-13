//
// Created by lavreniuk on 12.09.2020.
//

#ifndef ASTEROIDS_GAMEENTITY_H
#define ASTEROIDS_GAMEENTITY_H


#include <SDL2/SDL_render.h>
#include "DummyVector.h"
#include "DummyVectorMath.h"
#include "Globals.h"
#include <iostream>

class GameEntity {
protected:
    DummyVector* movementDirection;
    DummyVector* vectors;
    float x;
    float y;
    float limit = 5.0f;
    float power = 2.0f;
    size_t vectorsCount = 0;
    virtual void checkScreenCollision();
public:
    bool isAlive;
    virtual void update();
    virtual void render(SDL_Renderer* renderer);
    float getX() const{ return this->x; }
    float getY() const{ return this->y; }
};


#endif //ASTEROIDS_GAMEENTITY_H
