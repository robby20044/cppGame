#include "Tower.h"
#include "GameState.h"

Tower::Tower(GameState& gs, sf::Vector2f position, TowerType type) 
: gs(gs), position(position), type(type) {}

void Tower::build() {
    float width{};
    float height{};
    switch (type) {
        case 0:
            { 
            width = 40.f;
            height = 100.f;
            body = sf::RectangleShape({width, height});
            projectileOrigin = {position.x + width / 2, position.y};
            attackFrequency = 1;
            
            Marker m(projectileOrigin, 2.f, sf::Color::Green);
            gs.markers.push_back(m);
            
            break; 
            }
        default:
            break;
    }
    body.setPosition({position.x, position.y});
}


// update handles attacking and targeting
void Tower::update() {
    if (gs.enemies.size() > 0) {
        attackTimer -= gs.deltaTime;
        if (attackTimer <= 0) {
            attack();
        }
    }
    for (Projectile& p : projectiles) {
        p.update();
    }
}

void Tower::attack() {
    Projectile p(gs, Rock, projectileOrigin, gs.enemies[0].position);
    projectiles.push_back(p);
    resetAttackTimer();
}

void Tower::resetAttackTimer() {
    attackTimer = 1 / attackFrequency;
}