#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
class function
{
public:
	static void handleterraincollsion(sf::Vector2f& mapOffset,const sf::Vector2f& position,std::vector<std::vector<sf::Vector2f>>& terrains);
	static bool isPointInPolygon(const sf::Vector2f& point, const std::vector<sf::Vector2f>& polygon);
	static bool isMovementAllowed(const sf::Vector2f& newplayerpostion, const std::vector<std::vector<sf::Vector2f>>& terrains);
};

