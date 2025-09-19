#include<SFML/Graphics.hpp>
#include<iostream>
#include "Collision.h"
Collision::Collision()
{
	width = 20;
	height = 20;
}
//checking for collision and returning true or false
bool Collision::CollisionDetected(sf::FloatRect PlayerRect,sf::FloatRect EnemyRect)
{
	if (PlayerRect.left<EnemyRect.left + EnemyRect.width &&
		PlayerRect.left + PlayerRect.width>EnemyRect.left &&
		PlayerRect.top + PlayerRect.height > EnemyRect.top &&
		PlayerRect.top < EnemyRect.top + EnemyRect.height)
		return true;

	return false;
}
