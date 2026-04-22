#pragma once
#include <SFML/Graphics.hpp>

/*
* Marker is used to visualize positions by placing a small shape at a given
* location. 
*/
class Marker {
public:
    sf::CircleShape body;
    Marker(sf::Vector2f position, float size, sf::Color color);

private:
    float size{};
    sf::Vector2f position;
    sf::Color color;
};