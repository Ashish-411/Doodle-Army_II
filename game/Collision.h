#pragma once
#include<SFML/Graphics.hpp>
class Collision
{
private:
	int width;
	int height;
public:
	Collision();
	bool CollisionDetected(sf::FloatRect, sf::FloatRect);
};

