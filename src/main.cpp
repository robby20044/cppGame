#include <SFML/Window.hpp>
#include <iostream>
#include "GameState.h"

using std::cout;


void init(GameState& gs) {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    gs.window = sf::RenderWindow(sf::VideoMode({800, 600}), "game", 
                      sf::Style::Default, sf::State::Windowed, settings);
    gs.window.setFramerateLimit(120);
    gs.clock = sf::Clock();

    gs.entryPoint = {0, 300};
    gs.exitPoint = {800, 300};

    Tower t1(gs, {100.f, 100.f}, RockTosser);
    gs.towers.push_back(t1);
    gs.towers[0].build();

    Enemy e1({400.f, 200.f}, Basic);
    gs.enemies.push_back(e1);
}




void handleEvents(GameState& gs) {
    while (const std::optional event = gs.window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            gs.running = false;
            gs.window.close();
        }
        else if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
            if (key->scancode == sf::Keyboard::Scancode::A) {
                Enemy& enemy = gs.enemies[0];
                sf::Vector2f pos = enemy.body.getPosition();
                enemy.setPosition({pos.x - 500 * gs.deltaTime, pos.y});
            }
            // if (key->scancode == sf::Keyboard::Scancode::W) {
            //     Enemy& enemy = gs.enemies[0];
            //     sf::Vector2f pos = enemy.body.getPosition();
            //     enemy.setPosition({pos.x, pos.y - 500 * gs.deltaTime});
            // }
            // if (key->scancode == sf::Keyboard::Scancode::S) {
            //     Enemy& enemy = gs.enemies[0];
            //     sf::Vector2f pos = enemy.body.getPosition();
            //     enemy.setPosition({pos.x, pos.y + 500 * gs.deltaTime});
            // }
            // if (key->scancode == sf::Keyboard::Scancode::D) {
            //     Enemy& enemy = gs.enemies[0];
            //     sf::Vector2f pos = enemy.body.getPosition();
            //     enemy.setPosition({pos.x + 500 * gs.deltaTime, pos.y});
            // }
        }
    }
}


void update(GameState& gs) {
    gs.deltaTime = gs.clock.getElapsedTime().asSeconds();

    for (Tower& t : gs.towers) {
        t.update();
    }

    gs.clock.restart();
}


void draw(GameState& gs) {
    gs.window.clear(sf::Color::Black);
    for (Tower& t : gs.towers) {
        gs.window.draw(t.body);
        for (Projectile p : t.projectiles) {
            gs.window.draw(p.getBody());
        }
    }
    for (Enemy e : gs.enemies) {
        gs.window.draw(e.body);
    }
    gs.window.display();
}



int main() {
    GameState gs;
    init(gs);

    while (gs.running) {
        handleEvents(gs);
        update(gs);
        draw(gs);
    }

    return 0;
}

