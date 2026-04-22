#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

struct GameState;

// todo: change to enum class
enum ProjectileType { Rock };


/*
* Created by a tower and moved to a designated target location over time. 
*/
class Projectile {
public:
    Projectile(GameState& gs, ProjectileType type, sf::Vector2f originPostion, sf::Vector2f targetPosition);
    sf::CircleShape getBody();
    void update();
    float getLifetime();

private:
    ProjectileType type;
    sf::Vector2f targetPosition;
    sf::Vector2f originPosition;
    sf::CircleShape body;
    GameState& gs;
    float speed{};
    float distToTarget{};
    float timeToReachTarget{};
    float lifetime{};
    
    void move();
    void addLifetime(float deltaTime);

};