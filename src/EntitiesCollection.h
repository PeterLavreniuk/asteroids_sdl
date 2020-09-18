//
// Created by lavreniuk on 13.09.2020.
//

#ifndef ASTEROIDS_ENTITIESCOLLECTION_H
#define ASTEROIDS_ENTITIESCOLLECTION_H

#include <vector>
#include "Asteroid.h"
#include "ShipBullet.h"
#include "Ship.h"
#include "AsteroidsFactory.h"

class EntitiesCollection {
private:
    std::vector<Asteroid> asteroids;
    std::vector<ShipBullet> bullets;
    Ship* ship;
    AsteroidsFactory* asteroidsFactory;
    int aliveBulletsCount = 0;
    int aliveAsteroids = 0;
    int aliveBigAsteroids = 0;
    int aliveMediumAsteroids = 0;
    int aliveSmallAsteroids = 0;
    void createAsteroids(int count, AsteroidType type);
    void createAsteroids(int count, AsteroidType type, float x, float y);
public:
    EntitiesCollection(Ship* ship);
    void generateEntities();
    void updateEntities();
    void checkCollisions();
    void renderEntities(SDL_Renderer* renderer);
    void addEntity(ShipBullet* bullet);
};


#endif //ASTEROIDS_ENTITIESCOLLECTION_H
