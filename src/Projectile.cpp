#include "Projectile.h"
#include <cmath>
#include "utils.h"
#include <iostream>
#include "GameState.h"

Projectile::Projectile(GameState& gs, ProjectileType type, sf::Vector2f originPosition,
    sf::Vector2f targetPosition) : gs(gs), type(type), originPosition(originPosition), targetPosition(targetPosition) {
    switch (type) {
        case Rock:
            { float width = 10.f;
            speed = 160.f;
            body = sf::CircleShape(width);
            originPosition = {originPosition.x - width / 2, originPosition.y - width / 2};
            body.setPosition(originPosition);
            body.setFillColor(sf::Color::Red);
            break; }
        default:
            std::cout << "invalid projectile type" << '\n';
            break;
    }
    float xDist = abs(originPosition.x - targetPosition.x);
    float yDist = abs(originPosition.y - targetPosition.y);
    distToTarget = sqrt(xDist * xDist + yDist * yDist);
    timeToReachTarget = distToTarget / speed;
}

void Projectile::update() {
    addLifetime(gs.deltaTime);
    move();
}

void Projectile::move() {
    float progress = lifetime / timeToReachTarget;
    body.setPosition(lerp(originPosition, targetPosition, progress));
}

void Projectile::addLifetime(float deltaTime) {
    lifetime += deltaTime;
}

float Projectile::getLifetime() {
    return lifetime;
}

sf::CircleShape Projectile::getBody() {
    return body;
}