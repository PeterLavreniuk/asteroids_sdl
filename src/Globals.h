//
// Created by lavreniuk on 11.09.2020.
//

#ifndef ASTEROIDS_GLOBALS_H
#define ASTEROIDS_GLOBALS_H


#include <random>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SHIP_BULLETS_COUNT = 10;
const float BIG_ASTEROID_SCALE = 8.0f;
const float MID_ASTEROID_SCALE = 6.0f;
const float SMALL_ASTEROID_SCALE = 3.0f;
const float BIG_ASTEROID_COLLISION_RADIUS = 30.0f;
const float MID_ASTEROID_COLLISION_RADIUS = 23.0f;
const float SMALL_ASTEROID_COLLISION_RADIUS = 12.0f;

enum AsteroidType{
    ASTEROID_BIG_TYPE,
    ASTEROID_MID_TYPE,
    ASTEROID_SMALL_TYPE
};

static int diceRoll(int lowerBound, int upperBound){
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(lowerBound,upperBound);
    return distribution(generator);
}

#endif //ASTEROIDS_GLOBALS_H