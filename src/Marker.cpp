#include "Marker.h"

Marker::Marker(sf::Vector2f position, float size, sf::Color color)
    : size(size), color(color) {
        body = sf::CircleShape(size);
        position = {position.x - size / 2, position.y - size / 2};
        body.setPosition(position);
        body.setFillColor(color);
}