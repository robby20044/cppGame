cmake_minimum_required(VERSION 3.25)
project(my-game)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        3.0.0
)
FetchContent_MakeAvailable(SFML)

add_executable(my-game
    src/main.cpp
    src/utils.cpp
    src/tower.cpp
    src/projectile.cpp
    src/Enemy.cpp
    src/Marker.cpp
    src/Tile.cpp
    src/Grid.cpp
)
target_link_libraries(my-game PRIVATE SFML::Graphics SFML::Window SFML::System)