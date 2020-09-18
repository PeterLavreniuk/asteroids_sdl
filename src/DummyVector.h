//
// Created by lavreniuk on 10.09.2020.
//
#include "math.h"

#ifndef ASTEROIDS_DUMMYVECTOR_H
#define ASTEROIDS_DUMMYVECTOR_H


class DummyVector {
private:
public:
    float x;
    float y;
    DummyVector(float x, float y);
    void rotate(float angle);
    void multiply(float value);
    void divide(float value);
};


#endif //ASTEROIDS_DUMMYVECTOR_H
