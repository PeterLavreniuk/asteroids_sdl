//
// Created by lavreniuk on 10.09.2020.
//
#include <SDL2/SDL.h>
#include "ShipBullet.h"
#include "GameEntity.h"

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H


class Ship : public GameEntity{
private:
    void recalculatePower();
public:
    Ship(float x, float y);
    void rotate(float angle);
    void push();
    void slowDown();
    void update() override;
    void render(SDL_Renderer* renderer) override;
    ShipBullet* shoot();
    ~Ship();
};


#endif //ASTEROIDS_SHIP_H
