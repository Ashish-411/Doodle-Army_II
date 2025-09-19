#include "background.h"

background::background()
{

}

background::~background()
{
}

void background::load()
{
	if (backgrnd.loadFromFile("assests/Map/bgnew.png")) {
		bgsprite.setTexture(backgrnd);
		bgsprite.setScale(4.2, 3.8);
	}
}

void background::draw(sf::RenderWindow& window)
{
	window.draw(bgsprite);
}
