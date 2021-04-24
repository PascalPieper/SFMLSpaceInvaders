#include "CompHeader.h"
int main()
{

    GameManager gm;
    mat_m::SaveGameManager sgm("test");
    AssetManager am;
    gm.pSaveGameManager = &sgm;
    gm.pAssetManager = &am;




    sf::RenderWindow window(sf::VideoMode(360, 200), "SFML works!");

    //window.setSize(sf::Vector2u{ 1920, 1080 });
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    gm.CreateEntity<ScrollingBackground>(sf::Vector2f{ 0,0 });
    /*
    sf::Texture text;
    text.loadFromFile("rainerSmall.jpg");
    testa->EntitySprite.setTexture(text);
    */

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
   
        }
        gm.Update();
        
        window.clear();
        gm.Draw(window);
        window.display();
        gm.RefreshDeltatime();
    }

    return 0;
}