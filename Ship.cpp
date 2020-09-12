//
// Created by lavreniuk on 10.09.2020.
//

#include "Ship.h"
#include "ShipBullet.h"
#include "DummyVectorMath.h"

Ship::Ship(float x, float y) {
    this->vectorsCount = 3;
    vectors = new DummyVector[3]{
        DummyVector(-16, 16),
        DummyVector(0,-16),
        DummyVector(16,16)
    };

    this->limit = 2.0f;
    this->power = 0.0f;
    this->x = ((vectors[0].x + vectors[1].x + vectors[2].x) / 3) + x;
    this->y = ((vectors[0].y + vectors[1].y + vectors[2].y) / 3) + y;
    movementDirection = new DummyVector(vectors[1].x, vectors[1].y);
}

void Ship::rotate(float angle) {
    for(size_t i = 0; i < 3; ++i){
        vectors[i].rotate(angle);
    }
}

void Ship::push() {
    power += 10.0f;
    if(power > 100.0f){
        power = 100.0f;
    }
    if(power < 0.0f){
        power = 0.0f;
    }

    auto _dir = new DummyVector(vectors[1].x, vectors[1].y);

    auto _magnitude = DummyVectorMath::CalculateMagnitude(_dir);
    _dir->divide(_magnitude);

    movementDirection = _dir;
}

void Ship::slowDown() {
    power -= 5.0f;
    if(power <= 0.0f){
        power = 0.0f;
    }
}

void Ship::update() {
    recalculatePower();

    GameEntity::update();

    for(size_t i = 0; i < ShipBulletsCount; ++i){
        if(bullets[i].IsAlive) {
            bullets[i].update();
        }
    }
}

void Ship::render(SDL_Renderer *renderer) {
    GameEntity::render(renderer);

    for(size_t i = 0; i < ShipBulletsCount; ++i){
        if(bullets[i].IsAlive)
            bullets[i].render(renderer);
    }
}

Ship::~Ship() {
    delete [] vectors;
}

void Ship::shoot() {
    for(size_t i = 0; i < ShipBulletsCount; ++i){
        if(!bullets[i].IsAlive){
            bullets[i].IsAlive = true;
            bullets[i].setPosition(x,y,&vectors[1]);
            return;
        }
    }
}

void Ship::recalculatePower() {
    if(power > 0.0f){
        if(power > 20.0f) {
            power -= 0.25f;
        }
        else{
            power -= 0.1f;
        }
    }

    if(power <= 0.0f){
        power = 0;
    }
}
