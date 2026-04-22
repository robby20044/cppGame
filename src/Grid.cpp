#include "Grid.h"
#include <vector>
using std::vector;

Grid::Grid(){}

Grid::Grid(int windowWidth, int windowHeight, int tileSize) 
: tileSize(tileSize) {
    int id{}, x{}, y{};
    int xTileCount = windowWidth / tileSize;
    int yTileCount = windowHeight / tileSize;
    for (int i = 0; i < yTileCount; i++) {
        for (int j = 0; j < xTileCount; j++) {
            tiles.push_back(Tile(id++, x, y));
            x += tileSize;
        }
        x = 0;
        y += tileSize;
    }
}

