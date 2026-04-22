#pragma once
#include <SFML/Graphics.hpp>

struct Tile {
    int id{};
    int x{};
    int y{};
    Tile(int id, int x, int y);
};