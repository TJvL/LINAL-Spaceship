cmake_minimum_required(VERSION 3.13)
project(linal_spaceship)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(linal_spaceship
        source/Application.cpp
        source/game/Game.cpp
        source/game/WireModel.cpp
        source/math/Mesh.cpp
        source/game/Spaceship.cpp
        source/game/ShootingTarget.cpp
        source/game/Bullet.cpp
        source/game/GameObjectCreation.cpp
        source/math/Transform.cpp)

target_link_libraries(linal_spaceship sfml-graphics)
