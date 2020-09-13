//
// Created by lavreniuk on 11.09.2020.
//

#ifndef ASTEROIDS_SHIPBULLET_H
#define ASTEROIDS_SHIPBULLET_H


#include <SDL2/SDL_render.h>
#include "GameEntity.h"

class ShipBullet : public GameEntity {
public:
    ShipBullet(float x, float y, DummyVector *direction);
    void update() override;
    void render(SDL_Renderer* renderer) override;
    void checkScreenCollision() override;
};


#endif //ASTEROIDS_SHIPBULLET_H
