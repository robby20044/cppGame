#include "utils.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

void wallBounceCheck(const GameState& gs, const sf::CircleShape& circle, 
                float& xVel, float&yVel) {
    auto pos = circle.getPosition();
    float delta = gs.deltaTime;

    if (pos.x + (xVel * delta) < 0 || pos.x + (2 * circle.getRadius()) 
        + (xVel * delta) > gs.window.getSize().x) {
            xVel = -xVel;
        }
    if (pos.y + (yVel * delta) < 0 || pos.y + (2 * circle.getRadius())
        + (yVel * delta) > gs.window.getSize().y) {
            yVel = -yVel;
        }
}


sf::Vector2f lerp(sf::Vector2f origin, sf::Vector2f goal, float progress) {
    if (progress < 0 || progress > 1) {
        //throw std::invalid_argument("progress must be a float from 0 to 1");
    }
    sf::Vector2f newPos = origin + progress * (goal - origin);
    return newPos;
}
