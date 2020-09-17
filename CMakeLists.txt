cmake_minimum_required(VERSION 3.16)
project(asteroids)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED SDL2)

add_executable(asteroids main.cpp Ship.cpp Ship.h DummyVector.cpp DummyVector.h Globals.h ShipBullet.cpp ShipBullet.h DummyVectorMath.cpp DummyVectorMath.h Asteroid.cpp Asteroid.h GameEntity.cpp GameEntity.h EntitiesCollection.cpp EntitiesCollection.h ShipInputHandler.cpp ShipInputHandler.h)

target_link_libraries(asteroids PRIVATE SDL2 SDL2_image)
