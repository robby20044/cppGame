#include "Projectile.h"
#include <cmath>
#include "utils.h"
#include <iostream>
#include "GameState.h"

Projectile::Projectile(GameState& gs, ProjectileType type, sf::Vector2f originPosition,
    sf::Vector2f targetPosition) : gs(gs), type(type), originPosition(originPosition), 
    targetPosition(targetPosition) {
    switch (type) {
        case Rock:
            { float radius = 10.f;
            speed = 160.f;
            body = sf::CircleShape(radius);
            body.setPosition({originPosition.x - radius, originPosition.y - radius});
            body.setFillColor(sf::Color::Red);
            break; }
        default:
            std::cout << "invalid projectile type" << '\n';
            break;
    }
    /*
    * Computes distance and the time required to cover that distance to gauge
    * what position the projectile should be in based on how long it has
    * existed.
    */
    float xDist = abs(originPosition.x - targetPosition.x);
    float yDist = abs(originPosition.y - targetPosition.y);
    distToTarget = sqrt(xDist * xDist + yDist * yDist);
    timeToReachTarget = distToTarget / speed;
}

/*
* Updates the lifetime of the projectile and moves the projectile towards its
* target.
*/
void Projectile::update() {
    addLifetime(gs.deltaTime);
    move();
}

/* 
* Determines the progress of the projectile based on its lifetime and time 
* required to reach the target. Moves the projectile to a position further in 
* its trajectory based on this progress. 
*/
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