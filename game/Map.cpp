#include "Map.h"
#include<iostream>
Map::Map():tileWidth(64),tileHeight(64),mapWidth(50),mapHeight(30){
	viewCenterX = 0;
	viewCenterY = 0;
}

Map::~Map()
{
}

void Map::initialize()
{
	mapOffset = sf::Vector2f(0.0f, 0.0f);
}

void Map::load()
{
	if (mapTexture.loadFromFile("assests/Map/outpost2.png")) {
		mapSprite.setTexture(mapTexture);
		mapSprite.setPosition(-163, 0);
		std::cout << "map loaded" << std::endl;
	}
	else {
		std::cout << "Map texture not loaded";
	}
}

void Map::update(const sf::Vector2f& playerPosition)
{
	viewCenterX = playerPosition.x;
	viewCenterY = playerPosition.y;
	m_view.setCenter(playerPosition+mapOffset);
	m_view.setSize(800, 600);
	m_view.zoom(0.85);
	//m_view.move(mapOffset);
}

void Map::draw(sf::RenderWindow& window)
{
	window.setView(m_view);
	window.draw(mapSprite);
	window.setView(window.getDefaultView());
}
