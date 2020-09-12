//
// Created by lavreniuk on 12.09.2020.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H


#include <SDL2/SDL_render.h>
#include "GameEntity.h"

class Asteroid : GameEntity {
private:
    void generateRandomPosition();
    void generateRandomMovementDirection();
    enum AsteroidRotateDirection{
        ASTEROID_ROTATE_LEFT,
        ASTEROID_ROTATE_RIGHT,
        ASTEROID_ROTATE_UNDEFINED
    };
    AsteroidRotateDirection direction;
public:
    Asteroid();
    void update() override;
    void scale(float value);

    void render(SDL_Renderer* renderer) override;
};


#endif //ASTEROIDS_ASTEROID_H
