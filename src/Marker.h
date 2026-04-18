#pragma once
#include <SFML/Graphics.hpp>

class Marker {
    float size{};
    sf::Vector2f position;
    sf::Color color;
public:
    sf::CircleShape body;
    Marker(sf::Vector2f position, float size, sf::Color color);
};