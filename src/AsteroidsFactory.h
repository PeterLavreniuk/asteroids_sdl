//
// Created by lavreniuk on 18.09.2020.
//

#ifndef ASTEROIDS_ASTEROIDSFACTORY_H
#define ASTEROIDS_ASTEROIDSFACTORY_H


#include "Asteroid.h"

class AsteroidsFactory {
private:
    DummyVector* getAsteroidVectors();
    void scaleAsteroidShape(float value, DummyVector* shape);
    DummyVector* generateMovementDirection();
public:
    //todo pass current ship position - for dodge fast kill
    Asteroid* create(AsteroidType type, float x, float y);
    Asteroid* create(AsteroidType type);
};

#endif //ASTEROIDS_ASTEROIDSFACTORY_H
