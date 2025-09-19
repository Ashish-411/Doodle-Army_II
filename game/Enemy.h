#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Health.h"
#include"Map.h"
class Health;
class Enemy
{
private:
	int EnemyHealth;
	int Xindex;
	int Yindex;
	int width;
	int height;
	float magnitude;
	float enemyspeed;
	sf::Vector2f TempDirection;
	sf::Vector2f NormalizedVector;
	sf::Vector2f direction;
public:
	sf::Sprite Enemysprite;
	Enemy();
	void Initialize(sf::Texture& texture,bool& loadedTexture);
	const int getEnemyHealth();
	int setEnemyHealth(int hp);
	void ReducedEnemyHp(int hp);
	void EnemyUpdate(const sf::Vector2f&,float,Map& map);
	sf::Vector2f EnemyDirection(sf::Vector2f vector);
	void draw(sf::RenderWindow& window);
};

