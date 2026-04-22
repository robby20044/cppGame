#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
#include "Tower.h"
#include "Projectile.h"
#include "Marker.h"
#include "Grid.h"


struct GameState {
    bool running = true;
    float deltaTime = 0.f; // time between game loop iterations
    sf::RenderWindow window;
    sf::Clock clock;
    std::vector<Enemy> enemies; // all currently existing enemies
    std::vector<Tower> towers; // all currently existing towers
    std::vector<Marker> markers; // collection of markers
    std::vector<sf::RectangleShape> test;
    Grid grid;
};