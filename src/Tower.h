#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Projectile.h"

struct GameState;

// todo: change to enum class
enum TowerType { RockTosser };

// A tower targets and shoot projectiles at enemies.
class Tower {  
public:
    TowerType type;
    sf::Vector2f position;
    sf::RectangleShape body;

    // Collection of projectiles created by this tower
    std::vector<Projectile> projectiles;

    int targetIndex{};
    
    Tower(GameState& gs, sf::Vector2f position, TowerType type);
    
    /*  
    * Creates the shapes that compose the tower and set attributes based on the
    * tower's type. 
    */
    void build();
   
    /*
    * Handles the targeting, attacking, and updates the tower's projectiles
    */
    void update();
  
private:
  float attackTimer{};
  float attackFrequency{};
  GameState& gs;
  sf::Vector2f projectileOrigin;
  ProjectileType projType;
  void attack();
  void resetAttackTimer();
};
