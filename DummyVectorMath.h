//
// Created by lavreniuk on 12.09.2020.
//

#ifndef ASTEROIDS_DUMMYVECTORMATH_H
#define ASTEROIDS_DUMMYVECTORMATH_H

#include "math.h"
#include "DummyVector.h"


class DummyVectorMath {
public:
    static float CalculateMagnitude(DummyVector* vector);
    static float CalculateMagnitude(float x, float y);
};


#endif //ASTEROIDS_DUMMYVECTORMATH_H
