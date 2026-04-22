#include <SFML/Window.hpp>
#include <iostream>
#include "GameState.h"

using std::cout;


void init(GameState& gs) {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    gs.window = sf::RenderWindow(sf::VideoMode({1200, 800}), "game", 
                      sf::Style::Default, sf::State::Windowed, settings);
    gs.window.setFramerateLimit(120);
    gs.clock = sf::Clock();

    int winWidth = gs.window.getSize().x;
    int winHeight = gs.window.getSize().y;
    int tileSize = 50;
    gs.grid = Grid(winWidth, winHeight, tileSize);

    Tower t1(gs, {100.f, 100.f}, RockTosser);
    gs.towers.push_back(t1);
    gs.towers[0].build();

    Enemy e1({400.f, 50.f}, Basic);
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
        }
    }
}


void update(GameState& gs) {
    for (Tower& t : gs.towers) {
        t.update();
    }
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

    for (Marker m : gs.markers) {
        gs.window.draw(m.body);
    }
    for (sf::RectangleShape r : gs.test) {
        gs.window.draw(r);
    }

    for (Tile t : gs.grid.tiles) {
        sf::RectangleShape r({40, 40});
        r.setPosition({static_cast<float>(t.x), static_cast<float>(t.y)});
        gs.window.draw(r);
    }

    gs.window.display();
}


void debugMode(GameState& gs) {
    char input = 'c';
    do {
        if (input == 'c') {
            gs.clock.restart();
            handleEvents(gs);
            update(gs);
            draw(gs);
            gs.deltaTime = gs.clock.getElapsedTime().asSeconds();
        } else {
            break;
        }
    } while (std::cin >> input);
}

void run(GameState& gs) {
    while (gs.running) {
        gs.deltaTime = gs.clock.getElapsedTime().asSeconds();
        gs.clock.restart();
        handleEvents(gs);
        update(gs);
        draw(gs);
    }
}

int main() {
    GameState gs;
    init(gs);

    run(gs);
    // debugMode(gs);

    return 0;
}
