//
// Created by lavreniuk on 10.09.2020.
//
#include <SDL2/SDL.h>
#include "DummyVector.h"

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H


class Ship {
private:
    float x;
    float y;
    float power;
    DummyVector* vectors;
    DummyVector* movementDirection;
public:
    Ship(float x, float y);
    void rotate(float angle);
    void render(SDL_Renderer* renderer);
    void push();
    void slowDown();
    void update();
    ~Ship();
};


#endif //ASTEROIDS_SHIP_H
