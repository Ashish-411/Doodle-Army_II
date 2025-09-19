#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"Health.h"
#include"Enemy.h"
#include<vector>
class bullet
{
private:
	float magnitude;
	int width;
	int height;
	float Bulletspeed; 
	std::vector<sf::Vector2f> direction;
	sf::Vector2f TempDirection;
	sf::Vector2f NormalizedVector;
	// Cooldown timer and duration (in seconds)
	sf::Clock fireClock;
	float fireCooldown; // Cooldown of 0.3 seconds between shots
public:
	std::vector<sf::RectangleShape> Bullets;
	bullet();
	sf::Vector2f BulletDirection(sf::Vector2f vector);
	void BulletUpdate(sf::RenderWindow& window,sf::Vector2f playerposition);
	void BulletCollision(Enemy& enemy, Health& health);
	void draw(sf::RenderWindow& window);
};

