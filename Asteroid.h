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
    void scale();
    static int diceRoll(int lowerBound, int upperBound);
    void generateRandomPosition();
    void generateRandomMovementDirection();
    float getCollisionRadius(AsteroidType type);
public:
    Asteroid(AsteroidType type);
    Asteroid(AsteroidType type, float x, float y);
    void update() override;
    void render(SDL_Renderer* renderer) override;
    AsteroidType getType() { return type; }
    bool CollisionHappens(GameEntity* entity);
};


#endif //ASTEROIDS_ASTEROID_H
