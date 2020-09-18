cmake_minimum_required(VERSION 3.16)
project(asteroids)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED SDL2)

add_executable(asteroids src/main.cpp src/Ship.cpp src/Ship.h src/DummyVector.cpp src/DummyVector.h src/Globals.h src/ShipBullet.cpp src/ShipBullet.h src/DummyVectorMath.cpp src/DummyVectorMath.h src/Asteroid.cpp src/Asteroid.h src/GameEntity.cpp src/GameEntity.h src/EntitiesCollection.cpp src/EntitiesCollection.h src/ShipInputHandler.cpp src/ShipInputHandler.h src/AsteroidsFactory.cpp src/AsteroidsFactory.h)

target_link_libraries(asteroids PRIVATE SDL2 SDL2_image)
