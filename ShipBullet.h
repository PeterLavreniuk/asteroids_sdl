//
// Created by lavreniuk on 11.09.2020.
//

#ifndef ASTEROIDS_SHIPBULLET_H
#define ASTEROIDS_SHIPBULLET_H


#include <SDL2/SDL_render.h>
#include "GameEntity.h"

class ShipBullet : GameEntity {
public:
    bool IsAlive;
    ShipBullet();
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void checkScreenCollision() override;
    void setPosition(float x, float y, DummyVector* direction);
};


#endif //ASTEROIDS_SHIPBULLET_H
