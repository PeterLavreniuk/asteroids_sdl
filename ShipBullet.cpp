//
// Created by lavreniuk on 11.09.2020.
//

#include "ShipBullet.h"

void ShipBullet::render(SDL_Renderer *renderer) {
    SDL_RenderDrawPoint(renderer,
                        x,
                        y);
}



void ShipBullet::update() {
    GameEntity::update();
}

void ShipBullet::checkScreenCollision() {
    if(x > SCREEN_WIDTH || x < 0 ||
       y > SCREEN_HEIGHT || y < 0){
        this->isAlive = false;
    }
}

ShipBullet::ShipBullet(float x, float y, DummyVector *direction) {
    this->x = x;
    this->y = y;
    this->movementDirection = new DummyVector(direction->x, direction->y);
    this->isAlive = true;
}
