#pragma once
#include<SFML/Graphics.hpp>
class Map
{
public:
	Map();
	~Map();
	void initialize();
	void load();
	void update(const sf::Vector2f& playerPosition);
	void draw(sf::RenderWindow& window);
	sf::Vector2f mapOffset;
	sf::View m_view;
private:
	sf::Texture mapTexture;
	sf::Sprite mapSprite;

	int tileWidth;
	int tileHeight;

	int mapWidth;
	int mapHeight;
	float viewCenterX;
	float viewCenterY;

};

