//
// Created by lavreniuk on 12.09.2020.
//

#include "DummyVectorMath.h"

float DummyVectorMath::CalculateMagnitude(float x, float y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

float DummyVectorMath::CalculateMagnitude(DummyVector *vector) {
    return sqrt(pow(vector->x, 2) + pow(vector->y, 2));
}