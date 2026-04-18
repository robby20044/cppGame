#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"

void wallBounceCheck(const GameState& gs, const sf::CircleShape& circle, 
                float& xVel, float&yVel);

sf::Vector2f lerp(sf::Vector2f origin, sf::Vector2f goal, float);