//
// Created by lavreniuk on 10.09.2020.
//
#include <SDL2/SDL.h>
#include "ShipBullet.h"
#include "GameEntity.h"

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H


class Ship : GameEntity{
private:
    ShipBullet bullets[ShipBulletsCount];
    void recalculatePower();
public:
    Ship(float x, float y);
    void rotate(float angle);
    void push();
    void slowDown();
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void shoot();
    ~Ship();
};


#endif //ASTEROIDS_SHIP_H
