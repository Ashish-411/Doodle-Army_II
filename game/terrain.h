#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
class terrain
{

public:
	std::vector<std::vector<sf::Vector2f>> terrains;
	void initialize();
	void load();
	void update();
	void draw(sf::RenderWindow&);
	bool isOnterrain(const sf::Vector2f& playerposition, sf::Vector2f& mapOffset, const sf::View& view);

};

