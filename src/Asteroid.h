//
// Created by lavreniuk on 12.09.2020.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H


#include <SDL2/SDL_render.h>
#include "GameEntity.h"
#include "random"
#include "ShipBullet.h"

class Asteroid : public GameEntity {
private:
    enum AsteroidRotateDirection{
        ASTEROID_ROTATE_LEFT,
        ASTEROID_ROTATE_RIGHT,
        ASTEROID_ROTATE_UNDEFINED
    };
    AsteroidRotateDirection direction;
    AsteroidType type;
    float collisionRadius = 0.0f;
public:
    Asteroid(float x, float y, float collisionRadius,
             AsteroidType type, DummyVector* shape,
             DummyVector* movementDirection);
    void update() override;
    void render(SDL_Renderer* renderer) override;
    AsteroidType getType() { return type; }
    bool CollisionHappens(GameEntity* entity);
};


#endif //ASTEROIDS_ASTEROID_H
