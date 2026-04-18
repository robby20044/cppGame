#pragma once
#include <SFML/Graphics.hpp>

enum EnemyType { Basic };

class Enemy {
    float health{};

public:
    sf::CircleShape body;
    sf::Vector2f position;
    EnemyType type;

    Enemy(sf::Vector2f position, EnemyType type);
    void setPosition(sf::Vector2f position);
};