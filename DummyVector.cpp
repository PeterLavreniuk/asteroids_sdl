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

    auto _x = this->x * _cos - this->y * _sin;
    auto _y = this->x * _sin + this->y * _cos;
    this->x = _x;
    this->y = _y;
}

void DummyVector::scale(float value) {

}