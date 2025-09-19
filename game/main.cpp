#include<iostream>
#include<SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include"Player.h"
#include"Enemy.h"
#include"bullet.h"
#include"Collision.h"
#include"Health.h"
#include"Map.h"
#include"background.h"
#include"terrain.h"
#include"function.h"
#include"menu.h"
    enum class GameState {MainMenu,Playing,GameOver};
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DOOMS ARMY", sf::Style::Default);
    //--------------------------------------load objects
    GameState currentState = GameState::MainMenu;
    background back;
    Map map;
    terrain terrain;
    Player player;
    std::vector<Enemy>enemies;
    bullet Bullet;
    Collision collision;
    Health health;
    sf::Clock clock;
    sf::Clock EnemySpwan;
    sf::Texture texture;
    bool loadedTexture= texture.loadFromFile("assests/player/textures/Enemy.png");
    bool Detectedcollision=true;
    float spawninterval = 1.f;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    ///_________________________initialize____________
    map.initialize();
    terrain.initialize();
    player.initialize();
    health.initialize();

    //____________________________initialize______________
    ////____________________load_______________
    back.load();
    map.load();
    player.load();
    health.load();

    ///____________________load__________________

    //______________________main loop____________________
    while (window.isOpen()) {
       
        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                    break;
                }
            default:
            { break; }
            }
        }

        if (currentState == GameState::GameOver) {
            menu::displaygameover(window);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    // Reset the game state for a new playthrough
                    currentState = GameState::Playing;
                    // Reset health, enemies, and player position
                    std::cout << "space pressed" << std::endl;
                    health.reset();
                    enemies.clear();
                    player.initialize();

                }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
        if (currentState == GameState::MainMenu) {
            menu::displaymainmenu(window);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                std::cout << "Key entered" << std::endl;
                currentState = GameState::Playing;
                
            }
        }
        if (currentState == GameState::Playing) {
            // Handle the gameplay logic and rendering here
            sf::Time deltatimer = clock.restart();
            float deltatime = deltatimer.asSeconds();

            ////______________update_______________
            map.update(player.playerSprite.getPosition());
            player.update(deltatime, map);
            function::handleterraincollsion(map.mapOffset, player.playerSprite.getPosition(), terrain.terrains);
            //sending player position and window refrence for bullet update
            Bullet.BulletUpdate(window, player.playerSprite.getPosition());
            if (EnemySpwan.getElapsedTime().asSeconds() > spawninterval)
            {
                Enemy enemy;
                enemy.Initialize(texture, loadedTexture);
                enemies.push_back(enemy);
                EnemySpwan.restart();
            }
            for (auto& enemy : enemies)
            {
                enemy.EnemyUpdate(player.playerSprite.getPosition(), deltatime, map);
                Bullet.BulletCollision(enemy, health);
            }
            for (auto it = enemies.begin(); it != enemies.end();)
            {
                if (player.playerSprite.getGlobalBounds().intersects(it->Enemysprite.getGlobalBounds()))
                {
                    // Handle collision: e.g., decrease player health
                    health.setPlayerHealth(-10); // Example damage value
                    health.update();
                    // Erase the collided enemy
                    it = enemies.erase(it);
                    // `erase` returns an iterator to the next element
                }
                else if (it->getEnemyHealth() == 0)
                {
                    it = enemies.erase(it);
                }

                else
                {
                    ++it; // Move to the next enemy
                }
            }
            if (health.getPlayerHealth() == 0) { currentState = GameState::GameOver; }
             ///__________________update___________________________
             // -----------------------------CLEAR PREVIOUS FRAME
            window.clear(sf::Color::Black);
            // --------------------------Draw the new content
            back.draw(window);
            map.draw(window);
            terrain.draw(window);
            player.draw(window);
            Bullet.draw(window);//draws the bullet in every frame
            for (auto& enemy : enemies) {
                enemy.draw(window);
            }
            health.draw(window);
            // ------------------------Display the contents of the window
            window.display();
        }
    }
    return 0;
}