#include<iostream>
#include<SFML/Graphics.hpp>
#include "Health.h"
#include"Enemy.h"
Health::Health()
{
	PlayerHealth = 60;
	
    if (font.loadFromFile("assests/Fonts/Arial.ttf"))
    {
        std::cout << "successfully loaded font" << std::endl;
        health.setPosition(sf::Vector2f(10,10));
        health.setFont(font);
    }
    else
    {
        std::cout << "not loaded font" << std::endl;
    }
}
void Health::initialize()
{
    height = 30;
    width = 101;
    Xindex = 0;
    Yindex = 5;
}

void Health::load()
{
    if (texture.loadFromFile("assests/player/textures/health.png"))
    {
        health.setString("HP:");
        std::cout << "successfully loaded health" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(10.f, 40.f));
        sprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
    }
    else
    {
        std::cout << "not loaded font" << std::endl;
    }

}

void Health::update()
{
    health.setString("HP:");
    health.setPosition(sf::Vector2f(10, 10));
    sprite.setPosition(sf::Vector2f(10.f, 40.f));
    if (getPlayerHealth() == 50) {
        Yindex = 4;
        sprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
    }
    else if (getPlayerHealth() == 40)
    {
        Yindex = 3;
        sprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
    }
    else if (getPlayerHealth() == 30)
    {
        Yindex = 2;
        sprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
    }
    else if (getPlayerHealth() == 20)
    {
        Yindex = 1;
        sprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
    }
    else {
        Yindex = 0;
        sprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
    }
}

int Health:: getPlayerHealth()
{ return PlayerHealth; }
void Health::reset()
{
    Xindex = 0;
    Yindex = 5;
    PlayerHealth = 60;
    sprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));

}
int Health::setPlayerHealth(int hp)
{
    PlayerHealth += hp;
    health.setPosition(sf::Vector2f(400.f, 500.f));
    return PlayerHealth;
}
void Health::draw(sf::RenderWindow& window)
{
    window.draw(health);
    window.draw(sprite);
}
