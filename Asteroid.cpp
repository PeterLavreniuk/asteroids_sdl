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

Asteroid::Asteroid() {
    vectorsCount = 12;
    vectors = new DummyVector[12]{
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

    direction = static_cast<AsteroidRotateDirection>(rand() % ASTEROID_ROTATE_UNDEFINED);
    generateRandomPosition();
    generateRandomMovementDirection();
}

void Asteroid::scale(float value) {
    for(size_t i = 0; i < 12; ++i){
        vectors[i].multiply(value);
    }
}

void Asteroid::generateRandomPosition() {
    srand (time(NULL));

    auto leftScreenSide = rand() % 2;
    auto upScreenSide = rand() % 2;
    auto leftBound = SCREEN_WIDTH / 2 - 60;
    auto rightBound = SCREEN_WIDTH / 2 + 60;
    auto upperBound = SCREEN_HEIGHT / 2 + 60;
    auto lowerBound = SCREEN_HEIGHT / 2 - 60;

    auto _x = 0;
    auto _y = 0;

    if(leftScreenSide == 0){
        _x = rand() % leftBound;
    }
    else{
        _x = rand() % (SCREEN_WIDTH - rightBound) + rightBound;
    }

    if(upScreenSide == 0){
        _y = rand() % upperBound;
    }
    else{
        _y = rand() % (SCREEN_HEIGHT - lowerBound) + lowerBound;
    }

    std::cout << _x << " " << _y << std::endl;

    this->x = _x;
    this->y = _y;
}

void Asteroid::generateRandomMovementDirection() {
    srand (time(NULL));

    auto _x = rand() % 201 + (-100);
    auto _y = rand() % 201 + (-100);
    auto _vector = new DummyVector(_x , _y);
    _vector->multiply(5.0f);
    this->movementDirection = _vector;
}

void Asteroid::render(SDL_Renderer *renderer) {
    GameEntity::render(renderer);
}
