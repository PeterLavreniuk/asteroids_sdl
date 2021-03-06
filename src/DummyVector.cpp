//
// Created by lavreniuk on 10.09.2020.
//

#include "DummyVector.h"

DummyVector::DummyVector(float x, float y) {
    this->x = x;
    this->y = y;
}

void DummyVector::rotate(float angle) {
    auto angleRadian = angle * M_PI / 180.0f;
    auto _cos = (float)cos(angleRadian);
    auto _sin = (float)sin(angleRadian);

    auto _x = x * _cos - y * _sin;
    auto _y = x * _sin + y * _cos;
    x = _x;
    y = _y;
}

void DummyVector::multiply(float value) {
    x *= value;
    y *= value;
}

void DummyVector::divide(float value) {
    x /= value;
    y /= value;
}
