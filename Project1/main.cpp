#include <SFML/Graphics.hpp>
#include "FireEnemy.h"
#include "MoveEntity.h"
#include "GameManager.h"
#include <iostream>
int main()
{

    GameManager gm;
    mat_m::SaveGameManager sgm("test");
    gm.pSaveGameManager = &sgm;
    //gm.CreateEntity();

    MoveEntity me(sf::Vector2f{ 0,0 });

    sf::RenderWindow window(sf::VideoMode(360, 200), "SFML works!");
    window.setSize(sf::Vector2u{ 1920, 1080 });
    window.setFramerateLimit(60);
    Enemy enem;
    sf::Clock clock;
    sf::Time time;
    float dt = 0;
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
        
        time = clock.restart();
        float dt = time.asSeconds();


        window.clear();
        window.draw(enem.sprite);
        window.draw(me.EntitySprite);
        //window.draw(shape);
        window.display();
        
    }

    return 0;
}