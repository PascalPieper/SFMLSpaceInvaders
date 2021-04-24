#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream>
#include "AssetManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include <memory>
class Bullet;
int main()
{

    GameManager gm;
    mat_m::SaveGameManager sgm("test");
    AssetManager am;
    gm.pSaveGameManager = &sgm;
    gm.pAssetManager = &am;

    gm.CreateEntity<Bullet>(sf::Vector2f{ 0,0 });
    gm.CreateEntity<Entity>(sf::Vector2f{ 0,0 });



    sf::RenderWindow window(sf::VideoMode(360, 200), "SFML works!");
    window.setSize(sf::Vector2u{ 1920, 1080 });
    window.setFramerateLimit(60);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        std::cout << gm.GetDeltaTime();

        gm.Draw(window);
        window.clear();
        //window.draw(test->EntitySprite);
        window.display();
        gm.RefreshDeltatime();
    }

    return 0;
}