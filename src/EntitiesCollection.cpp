//
// Created by lavreniuk on 13.09.2020.
//

#include "EntitiesCollection.h"

void EntitiesCollection::updateEntities() {
    ship->update();

    std::vector<int> asteroidsToRemove;
    for(size_t i = 0; i < asteroids.size(); ++i){
        auto &asteroid = asteroids[i];
        asteroid.update();
        if(!asteroid.isAlive){
            asteroidsToRemove.push_back(i);
            --aliveAsteroids;
            auto type = asteroid.getType();
            if(type == ASTEROID_BIG_TYPE){
                --aliveBigAsteroids;
                createAsteroids(2, ASTEROID_MID_TYPE, asteroid.getX(), asteroid.getY());
            }
            if(type == ASTEROID_MID_TYPE){
                --aliveMediumAsteroids;
                createAsteroids(2, ASTEROID_SMALL_TYPE, asteroid.getX(), asteroid.getY());
            }
            if(type == ASTEROID_SMALL_TYPE){
                --aliveSmallAsteroids;
            }
        }
    }

    std::vector<int> bulletsToRemove;
    for(size_t i = 0; i < bullets.size(); ++i){
        bullets[i].update();
        if(!bullets[i].isAlive){
            bulletsToRemove.push_back(i);
            --aliveBulletsCount;
        }
    }

    for(size_t i = 0; i < asteroidsToRemove.size(); ++i){
        asteroids.erase(asteroids.begin() + asteroidsToRemove[i]);
    }

    for(size_t i = 0; i < bulletsToRemove.size(); ++i){
        bullets.erase(bullets.begin() + bulletsToRemove[i]);
    }
}

void EntitiesCollection::checkCollisions() {
    for(size_t i = 0; i < bullets.size(); ++i){
        auto &bullet = bullets[i];
        if(!bullet.isAlive)
            continue;

        for(size_t j = 0; j < asteroids.size(); ++j){
            auto &asteroid = asteroids[j];
            if(!asteroid.isAlive)
                continue;

            if(asteroid.CollisionHappens(&bullet)){
                bullet.isAlive = false;
                asteroid.isAlive = false;
            }
        }
    }
}

void EntitiesCollection::renderEntities(SDL_Renderer *renderer) {
    ship->render(renderer);
    for(size_t i = 0; i < asteroids.size(); ++i){
        auto asteroid = asteroids[i];
        if(!asteroid.isAlive)
            continue;

        asteroids[i].render(renderer);
    }

    for(size_t i = 0; i < bullets.size(); ++i){
        auto bullet = bullets[i];
        if(!bullet.isAlive)
            continue;

        bullets[i].render(renderer);
    }
}

EntitiesCollection::EntitiesCollection(Ship *ship) {
    this->ship = ship;
    this->asteroidsFactory = new AsteroidsFactory();
}

void EntitiesCollection::generateEntities() {
    if(aliveBigAsteroids <= 0 && aliveMediumAsteroids <= 1){
        createAsteroids(3, ASTEROID_BIG_TYPE);
        return;
    }
}

void EntitiesCollection::addEntity(ShipBullet *bullet) {
    if(SHIP_BULLETS_COUNT > aliveBulletsCount){
        bullets.push_back(*bullet);
        ++aliveBulletsCount;
    }
}

void EntitiesCollection::createAsteroids(int count, AsteroidType type) {
    for(int i = 0; i < count; ++i) {
        auto asteroid = asteroidsFactory->create(type);
        asteroids.push_back(*asteroid);
        ++aliveAsteroids;
        if(type == ASTEROID_SMALL_TYPE)
            ++aliveSmallAsteroids;
        if(type == ASTEROID_MID_TYPE)
            ++aliveMediumAsteroids;
        if(type == ASTEROID_BIG_TYPE)
            ++aliveBigAsteroids;
    }
}

void EntitiesCollection::createAsteroids(int count, AsteroidType type, float x, float y) {
    for(int i = 0; i < count; ++i) {
        auto asteroid = asteroidsFactory->create(type, x, y);
        asteroids.push_back(*asteroid);
        ++aliveAsteroids;
        if(type == ASTEROID_SMALL_TYPE)
            ++aliveSmallAsteroids;
        if(type == ASTEROID_MID_TYPE)
            ++aliveMediumAsteroids;
        if(type == ASTEROID_BIG_TYPE)
            ++aliveBigAsteroids;
    }
}
