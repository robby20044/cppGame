#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"

struct GameState;

enum TowerType { RockTosser };

class Tower {
    void attack();
    void resetAttackTimer();
    
public:
    TowerType type;
    sf::Vector2f position;
    sf::RectangleShape body;
    std::vector<Projectile> projectiles;
    sf::Vector2f projectileOrigin;
    GameState& gs;
    int targetIndex{};
    float attackTimer{};
    float attackFrequency{};
    
    Tower(GameState& gs, sf::Vector2f position, TowerType type);
    void build();
    void update();
};
