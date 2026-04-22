#pragma once
#include <SFML/Graphics.hpp>

// todo: change to enum class 
enum EnemyType { Basic };

/*
* Target of towers. Will move along a predetermined path and will deal take away
* health if end is reached.
*/
class Enemy {
public:
    sf::CircleShape body;
    sf::Vector2f position;
    EnemyType type;

    Enemy(sf::Vector2f position, EnemyType type);
    void setPosition(sf::Vector2f position);

private:
    float health{};

};