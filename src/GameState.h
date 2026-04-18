#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
#include "Tower.h"
#include "Projectile.h"
#include "Marker.h"


struct GameState {
    bool running = true;
    float deltaTime = 0.f;
    sf::RenderWindow window;
    sf::Clock clock;
    std::vector<Enemy> enemies;
    std::vector<Tower> towers;
    sf::Vector2f entryPoint;
    sf::Vector2f exitPoint;
    std::vector<Marker> markers;
    float totalSeconds{};
};