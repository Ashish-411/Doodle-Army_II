#pragma once
#include<SFML/Graphics.hpp>
class background
{
	sf::Texture backgrnd;
	sf::Sprite bgsprite;
public:
	background();
	~background();
	void load();
	void draw(sf::RenderWindow&);
};

