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

Asteroid::Asteroid(AsteroidType type) {
    this->type = type;
    this->isAlive = true;
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
    direction = static_cast<AsteroidRotateDirection>(diceRoll(0,ASTEROID_ROTATE_UNDEFINED));
    power = 1.0f;
    limit = 2.0f;
    collisionRadius = getCollisionRadius(type);
    generateRandomPosition();
    generateRandomMovementDirection();
    scale();
}

Asteroid::Asteroid(AsteroidType type, float x, float y) {
    this->type = type;
    this->isAlive = true;
    this->x = x;
    this->y = y;
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
    direction = static_cast<AsteroidRotateDirection>(diceRoll(0,ASTEROID_ROTATE_UNDEFINED));
    power = 1.0f;
    limit = 2.0f;
    collisionRadius = getCollisionRadius(type);
    generateRandomMovementDirection();
    scale();
}


void Asteroid::generateRandomPosition() {
    auto leftScreenSide = diceRoll(0,2);
    auto upScreenSide = diceRoll(0,2);
    auto leftBound = SCREEN_WIDTH / 2 - 60;
    auto rightBound = SCREEN_WIDTH / 2 + 60;
    auto upperBound = SCREEN_HEIGHT / 2 + 60;
    auto lowerBound = SCREEN_HEIGHT / 2 - 60;

    int _x, _y;

    if(leftScreenSide == 0){
        _x = diceRoll(0, leftBound);
    }
    else{
        _x = diceRoll(rightBound, SCREEN_WIDTH);
    }

    if(upScreenSide == 0){
        _y = diceRoll(0, upperBound);

    }
    else{
        _y = diceRoll(lowerBound, SCREEN_HEIGHT);
    }

    this->x = _x;
    this->y = _y;

    std::cout<< x << " " << y  << std::endl;
}

void Asteroid::generateRandomMovementDirection() {
    auto _x = diceRoll(-100,100);
    auto _y = diceRoll(-100, 100);
    auto _vector = new DummyVector(_x , _y);
    _vector->multiply(5.0f);
    this->movementDirection = _vector;
}

void Asteroid::render(SDL_Renderer *renderer) {
    GameEntity::render(renderer);
}

void Asteroid::scale() {
    auto value = 0.0f;
    switch (this->type) {
        case ASTEROID_BIG_TYPE:
            value = BIG_ASTEROID_SCALE;
            break;
        case ASTEROID_MID_TYPE:
            value = MID_ASTEROID_SCALE;
            break;
        case ASTEROID_SMALL_TYPE:
            value = SMALL_ASTEROID_SCALE;
            break;
        default:
            value = 1.0f;
            break;
    }
    for(size_t i = 0; i < 12; ++i){
        vectors[i].multiply(value);
    }
}

int Asteroid::diceRoll(int lowerBound, int upperBound) {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(lowerBound,upperBound);
    int diceRoll =  distribution(generator);
    return diceRoll;
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

float Asteroid::getCollisionRadius(AsteroidType type) {
    switch (type) {
        case ASTEROID_BIG_TYPE:
            return BIG_ASTEROID_COLLISION_RADIUS;
        case ASTEROID_MID_TYPE:
            return MID_ASTEROID_COLLISION_RADIUS;
        case ASTEROID_SMALL_TYPE:
            return SMALL_ASTEROID_COLLISION_RADIUS;
        default:
            return 0.0f;
    }
}