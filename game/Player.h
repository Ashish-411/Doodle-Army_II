#pragma once
#include<SFML/Graphics.hpp>
#include"Map.h"
#include"terrain.h"
class Player
{
private:
    sf::Texture playerTexture;
    int Xindex;
    int Yindex;
    int width;
    int height;
    float speed;
    float gravity;
    float animationspeed;
public:
    sf::Sprite playerSprite;
    Player();
    ~Player();
    void initialize();
    void load();
    void update(float deltatime, Map& map);
    void draw(sf::RenderWindow& window);

};

