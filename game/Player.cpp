#include<iostream>
#include<SFML/Graphics.hpp>
#include "Player.h"
#include"bullet.h"
#include"function.h"
Player::Player()
{
    Xindex = 0;
    Yindex = 0;
    width = 30;
    height = 34;
    speed = 200.f;
    gravity = 250.f;
    animationspeed = 0.2f;
    
}
Player::~Player()
{
}
void Player::initialize()
{
}
void Player::load()
{
    if (playerTexture.loadFromFile("assests/player/textures/player.png"))
    {
        std::cout << "texture successfully loaded" << std::endl;
        playerSprite.setTexture(playerTexture);
        playerSprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
        playerSprite.setScale(sf::Vector2f(2.5, 2.5));
        playerSprite.setOrigin(sf::Vector2f(15, 30));
        playerSprite.setPosition(sf::Vector2f(200, 300));
    }
    else
    {
        std::cout << "Loading failed" << std::endl;
    }
}


void Player::update(float deltatime, Map& map)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Xindex = 0;
        Yindex = 1;
        playerSprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
        map.mapOffset.x += speed * deltatime;
    }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        Xindex = 2;
        Yindex = 0;
        playerSprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
        map.mapOffset.y += speed * deltatime;
    }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Xindex = 3;
        Yindex = 0;
        playerSprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
        map.mapOffset.x -= speed * deltatime;
    }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        Xindex = 2;
        Yindex = 0;
        playerSprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
        map.mapOffset.y -= speed * deltatime;
    }
    else {
        playerSprite.setTextureRect(sf::IntRect(0, 0, width, height));
        map.mapOffset.y += gravity * deltatime;
    }
  
}
    void Player::draw(sf::RenderWindow & window)
    {
        window.draw(playerSprite);
    }