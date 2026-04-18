#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, EnemyType type) 
: position(position), type(type) {
    body = sf::CircleShape(20.f);
    body.setPosition(position);
    switch (type) {
        case Basic:
            health = 100;
            break;
        default:
            break;
    }
}

void Enemy::setPosition(sf::Vector2f position) {
    this->position = position;
    body.setPosition(position);
}