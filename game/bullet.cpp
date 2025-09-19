#include<SFML/Graphics.hpp>
#include<iostream>
#include "bullet.h"
#include"Player.h"
#include"Enemy.h"
#include<math.h>

bullet::bullet()
{
	Bulletspeed = 0.5f;
	width = 28;
	height = 32;
	magnitude = 0.f;//initializing value of magnitude to 0
	fireCooldown = 0.3f;//cooldown of 0.3sec
	NormalizedVector = sf::Vector2f(0.f,0.f);
}
sf::Vector2f bullet::BulletDirection(sf::Vector2f vector) 
{
	magnitude = vector.x * vector.x + vector.y * vector.y;
	float Magnitude = std::sqrt(magnitude);//gives the resultant of a vector
	NormalizedVector = vector / Magnitude;//returns unit vector
	return NormalizedVector;
}
void bullet::BulletUpdate(sf::RenderWindow& window,sf::Vector2f playerposition)
{
	sf::Vector2f mousePositionF = sf::Vector2f(sf::Mouse::getPosition(window)); // Get mouse position relative to the window
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireClock.getElapsedTime().asSeconds() >= fireCooldown)
	{
		Bullets.push_back(sf::RectangleShape(sf::Vector2f(20.f, 5.f)));
		direction.push_back(sf::Vector2f(0.f, 0.f));
		int a = Bullets.size()-1;//last bullet index
		int b = direction.size() - 1;
		Bullets[a].setPosition(playerposition+sf::Vector2f(0.f,-30.f));//sets bullet position in refrence to player sprite	
		TempDirection = mousePositionF - Bullets[a].getPosition();//calculating the difference and storing in temporary variable
		//passing the temporary bullet direction of each bullet
		direction[b] = BulletDirection(TempDirection);
		float Bullet_angle = std::atan2(direction[b].y, direction[b].x) * 180 / 3.14159265f; // Convert radians to degrees
		Bullets[a].setRotation(Bullet_angle);
		fireClock.restart();	
	}
	//moving the bullet
	for (size_t i = 0; i < Bullets.size(); i++) {
		Bullets[i].setPosition(Bullets[i].getPosition() + direction[i]* Bulletspeed);
	}


}
void bullet::BulletCollision(Enemy& enemy, Health& health)
{
	for (size_t i = 0; i < Bullets.size(); i++)
	{
			if (Bullets[i].getGlobalBounds().intersects(enemy.Enemysprite.getGlobalBounds())) {
				//detection of collision
					enemy.ReducedEnemyHp(100);
					// Removing both direction and bullet when collided
					Bullets.erase(Bullets.begin() + i);
					direction.erase(direction.begin() + i);
			}
			else { continue; }
	}

}
void bullet::draw(sf::RenderWindow& window)
{
		
	for(size_t i=0;i<Bullets.size();i++)
	{
		window.draw(Bullets[i]);
	}
	
}
