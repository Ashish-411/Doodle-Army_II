#include "menu.h"

void menu::displaymainmenu(sf::RenderWindow & window) {
    sf::Font font;
    font.loadFromFile("assests/Fonts/recharge.otf"); // Load your font here
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("assests/Map/bgnew.png");
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(2, 2));
    sf::Text title("DOOM'S ARMY", font, 50);
    title.setFillColor(sf::Color::Black);
    sf::Text playText("Press Enter to Play", font, 30);
    title.setPosition(140, 150);
    playText.setPosition(200, 350);

    window.clear();
    window.draw(sprite);
    window.draw(title);
    window.draw(playText);
    window.display();
}

void menu::displaygameover(sf::RenderWindow& window) {
    sf::Font font;
    font.loadFromFile("assests/Fonts/BlackOps.ttf"); // Load your font here
    sf::Font font2;
    font2.loadFromFile("assests/Fonts/recharge.otf"); // Load your font here
    sf::Text gameOverText("GAME OVER", font, 50);
    sf::Text retryText("Press Space to Retry or Esc to Quit", font2, 30);
    gameOverText.setPosition(250, 150);
    retryText.setPosition(70, 350);

    window.clear();
    window.draw(gameOverText);
    window.draw(retryText);
    window.display();
}

