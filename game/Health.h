#pragma once
#include<SFML/Graphics.hpp>
#include"Enemy.h"
class Enemy;
class Health
{
private:
	int height;
	int width;
	int Xindex;
	int Yindex;
	int PlayerHealth;
	sf::Text health;
	sf::Font font;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Health();
	void initialize();
	void load();
	void update();
	int getPlayerHealth();
	void reset();
	int setPlayerHealth(int hp);
	void draw(sf::RenderWindow& window);

};

