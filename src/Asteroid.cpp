//
// Created by lavreniuk on 12.09.2020.
//

#include "Asteroid.h"

void Asteroid::update() {
    GameEntity::update();

    auto angle = 0.0f;
    if(direction == ASTEROID_ROTATE_LEFT){
        angle = -1.0f;
    }
    if(direction == ASTEROID_ROTATE_RIGHT){
        angle = 1.0f;
    }

    for(size_t i = 0; i < 12; ++i){
        vectors[i].rotate(angle);
    }
}

void Asteroid::render(SDL_Renderer *renderer) {
    GameEntity::render(renderer);
}

bool Asteroid::CollisionHappens(GameEntity *entity) {
    float totalRadius = pow(this->collisionRadius + 0.5f, 2);
    auto dx = this->x - entity->getX();
    auto dy = this->y - entity->getY();
    float distance = pow(dx,2) + pow(dy,2);
    if(distance < totalRadius){
        return true;
    }
    return false;
}

Asteroid::Asteroid(float x, float y, float collisionRadius,
                   AsteroidType type, DummyVector *shape,
                   DummyVector* movementDirection) {
    this->type = type;
    this->x = x;
    this->y = y;
    this->vectors = shape;
    this->collisionRadius = collisionRadius;
    this->movementDirection = movementDirection;
    vectorsCount = 12;
    direction = static_cast<AsteroidRotateDirection>(diceRoll(0,ASTEROID_ROTATE_UNDEFINED));
    power = 1.0f;
    limit = 2.0f;
}
