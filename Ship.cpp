//
// Created by lavreniuk on 10.09.2020.
//

#include "Ship.h"

Ship::Ship(float x, float y)  {
    this->power = 0;
    this->vectors = new DummyVector[3]{
        DummyVector(-16, 16),
        DummyVector(0,-16),
        DummyVector(16,16)
    };

    this->movementDirection = new DummyVector(vectors[1].x, vectors[1].y);

    auto _x = ((vectors[0].x + vectors[1].x + vectors[2].x) / 3) + x;
    auto _y = ((vectors[0].y + vectors[1].y + vectors[2].y) / 3) + y;

    this->x = _x;
    this->y = _y;
}

void Ship::rotate(float angle) {
    for(size_t i = 0; i < 3; ++i){
        vectors[i].rotate(angle);
    }
}

void Ship::push() {
    auto _power = this->power + 0.06f;
    if(_power > 1.0f){
        _power = 1.0f;
    }
    if(_power < 0.0f){
        _power = 0.0f;
    }

    this->power = _power;
    this->movementDirection = new DummyVector(vectors[1].x, vectors[1].y);
}

void Ship::slowDown() {

}

void Ship::update() {
    auto _power = this-> power;
    if(_power > 0.0f){
        _power -= 0.01f;
    }
    if(_power < 0.0f){
        this->power = 0;
        return;
    }
    this->power = _power;

    this->movementDirection->x *= (_power);
    this->movementDirection->y *= (_power);

    this->x += this->movementDirection->x;
    this->y += this->movementDirection->y;
}

void Ship::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer,
                       vectors[0].x + this->x,
                       vectors[0].y + this->y,
                       vectors[1].x + this->x,
                       vectors[1].y + this->y);
    SDL_RenderDrawLine(renderer,
                       vectors[1].x + this->x,
                       vectors[1].y + this->y,
                       vectors[2].x + this->x,
                       vectors[2].y + this->y);
    SDL_RenderDrawLine(renderer,
                       vectors[2].x + this->x,
                       vectors[2].y + this->y,
                       vectors[0].x + this->x,
                       vectors[0].y + this->y);
}

Ship::~Ship() {
    delete [] this->vectors;
}