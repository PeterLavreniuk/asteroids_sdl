//
// Created by lavreniuk on 12.09.2020.
//

#include "GameEntity.h"

void GameEntity::update() {
    if(movementDirection == nullptr)
        return;

    auto _movementDirection = new DummyVector(movementDirection->x, movementDirection->y);
    _movementDirection->multiply(power);

    auto _magnitude = DummyVectorMath::CalculateMagnitude(_movementDirection);
    if(_magnitude > limit){
        auto ratio = limit / _magnitude;

        _movementDirection->multiply(ratio);
    }

    movementDirection = _movementDirection;

    x += movementDirection->x;
    y += movementDirection->y;

    checkScreenCollision();
}

void GameEntity::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    for(size_t i = 0; i < vectorsCount; ++i){
        size_t j = i + 1;
        if(j >= vectorsCount){
            j = 0;
        }

        SDL_RenderDrawLine(renderer,
                           vectors[i].x + this->x,
                           vectors[i].y + this->y,
                           vectors[j].x + this->x,
                           vectors[j].y + this->y);

    }
}

void GameEntity::checkScreenCollision() {
    if(x > SCREEN_WIDTH){
        x = 0;
    }
    if(x < 0){
        x = SCREEN_WIDTH;
    }
    if(y > SCREEN_HEIGHT){
        y = 0;
    }
    if(y < 0){
        y = SCREEN_HEIGHT;
    }
}