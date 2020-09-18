//
// Created by lavreniuk on 18.09.2020.
//

#include "AsteroidsFactory.h"

Asteroid *AsteroidsFactory::create(AsteroidType type, float x, float y) {
    auto asteroidShape = getAsteroidVectors();
    auto movementDirection = generateMovementDirection();
    switch (type) {
        case ASTEROID_BIG_TYPE:
            scaleAsteroidShape(BIG_ASTEROID_SCALE, asteroidShape);
            return new Asteroid(x, y, BIG_ASTEROID_COLLISION_RADIUS,
                                type, asteroidShape, movementDirection);
        case ASTEROID_MID_TYPE:
            scaleAsteroidShape(MID_ASTEROID_SCALE, asteroidShape);
            return new Asteroid(x, y, MID_ASTEROID_COLLISION_RADIUS,
                                type, asteroidShape, movementDirection);
        case ASTEROID_SMALL_TYPE:
            scaleAsteroidShape(SMALL_ASTEROID_SCALE, asteroidShape);
            return new Asteroid(x, y, SMALL_ASTEROID_COLLISION_RADIUS,
                                type, asteroidShape, movementDirection);
    }
    return nullptr;
}

Asteroid *AsteroidsFactory::create(AsteroidType type) {
    auto leftScreenSide = diceRoll(0,2);
    auto upScreenSide = diceRoll(0,2);


    auto _x = leftScreenSide == 0 ? diceRoll(0, SCREEN_WIDTH / 2 - 60)
                                    : diceRoll(SCREEN_WIDTH / 2 + 60, SCREEN_WIDTH);

    auto _y = upScreenSide == 0 ? diceRoll(0, SCREEN_HEIGHT / 2 + 60)
            : diceRoll(SCREEN_HEIGHT / 2 - 60, SCREEN_HEIGHT);

    return create(type, _x, _y);
}

//todo append some another asteroid shapes
DummyVector *AsteroidsFactory::getAsteroidVectors() {
    return new DummyVector[12]{
            DummyVector(-1, -4),
            DummyVector(1, -4),
            DummyVector(3, -3),
            DummyVector(4, -1),
            DummyVector(4, 2),
            DummyVector(2, 3),
            DummyVector(2, 4),
            DummyVector(-2, 4),
            DummyVector(-3, 3),
            DummyVector(-3, 2),
            DummyVector(-4, 1),
            DummyVector(-4, -2),
    };
}

void AsteroidsFactory::scaleAsteroidShape(float value, DummyVector* shape) {
    for(size_t i = 0; i < 12; ++i){
        shape[i].multiply(value);
    }
}

DummyVector *AsteroidsFactory::generateMovementDirection() {
    auto _x = diceRoll(-100,100);
    auto _y = diceRoll(-100, 100);
    auto _vector = new DummyVector(_x , _y);
    _vector->multiply(5.0f);
    return _vector;
}
