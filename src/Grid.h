#pragma once
#include "Tile.h"
#include <vector>
using std::vector;

class Grid {
public:
    int tileSize{};
    vector<Tile> tiles;
    Grid();
    Grid(int windowWidth, int windowHeight, int tileSize);

};