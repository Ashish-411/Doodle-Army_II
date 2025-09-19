#include<SFML/Graphics.hpp>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Enemy.h"
#include"Health.h"
#include"Map.h"
Enemy::Enemy()
{
	EnemyHealth = 100;
	Xindex = 0;
	Yindex = 0;
	width = 110;
	height = 124;
	magnitude = 0.f;
	enemyspeed = 200.f;
}
void Enemy::Initialize(sf::Texture& texture,bool& loadedTexture)
{
	if (loadedTexture)
	{
		std::cout << "Enemy Texture Loaded" << std::endl;
		Enemysprite.setTexture(texture);
		Enemysprite.setTextureRect(sf::IntRect(Xindex * width, Yindex * height, width, height));
		Enemysprite.setPosition(sf::Vector2f(800,rand()% 600));
		Enemysprite.setScale(sf::Vector2f(0.5, 0.5));
	}
	else {
		std::cout << "Enemy sprite loading failed" << std::endl;
	}


}
const int Enemy::getEnemyHealth()
{
	return EnemyHealth;
}
int Enemy::setEnemyHealth(int hp)
{
	EnemyHealth = hp;
	return EnemyHealth;
}
void Enemy::ReducedEnemyHp(int hp)
{
	EnemyHealth -= hp;
}
sf::Vector2f Enemy::EnemyDirection(sf::Vector2f vector)
{
	magnitude = vector.x * vector.x + vector.y * vector.y;
	float Magnitude = std::sqrt(magnitude);//gives the resultant of a vector
	NormalizedVector = vector / Magnitude;//returns unit vector
	return NormalizedVector;
}
void Enemy:: EnemyUpdate(const sf::Vector2f& playerposition,float deltatime,Map& map)
{
	sf::Vector2f targetposition = sf::Vector2f(playerposition.x, playerposition.y - 50);
	TempDirection = targetposition - Enemysprite.getPosition();
	direction = EnemyDirection(TempDirection);
	Enemysprite.setPosition(Enemysprite.getPosition()+ (direction * deltatime * enemyspeed));
	
}
void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(Enemysprite);
}