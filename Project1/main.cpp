
/*
#include "CompHeader.h"
int main()
{

    GameManager gm;
    mat_m::SaveGameManager sgm("test");
    AssetManager am;
    gm.pSaveGameManager = &sgm;
    gm.pAssetManager = &am;




    sf::RenderWindow window(sf::VideoMode(360, 200), "SFML works!");

    window.setSize(sf::Vector2u{ 1920, 1080 });
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    gm.CreateEntity<ScrollingBackground>(sf::Vector2f{ 0,0 });

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
}*/

#include <SFML/OpenGL.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "CompHeader.h"
int main()
{
    GameManager gm;
    mat_m::SaveGameManager sgm("test");
    AssetManager am;
    gm.pSaveGameManager = &sgm;
    gm.pAssetManager = &am;

    sf::RenderWindow window(sf::VideoMode(360, 200), "SFML works!");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    sf::Color bgColor;

    float color[3] = { 0.f, 0.f, 0.f };

    // let's use char array as buffer, see next part
    // for instructions on using std::string with ImGui
    char windowTitle[255] = "ImGui + SFML = <3";

    window.setTitle(windowTitle);
    window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Sample window"); // begin window

                                       // Background color edit
        if (ImGui::ColorEdit3("Background color", color)) {
            // this code gets called if color value changes, so
            // the background color is upgraded automatically!
            bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
            bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
            bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
        }
        float f;
        if (ImGui::SliderFloat("float", &f, 0.0f, 1.0f))
        {
            std::cout << f;
        }

        // Window title text edit
        ImGui::InputText("Window title", windowTitle, 255);

        if (ImGui::Button("Update window title")) {
            // this code gets if user clicks on the button
            // yes, you could have written if(ImGui::InputText(...))
            // but I do this to show how buttons work :)
            window.setTitle(windowTitle);
        }
        ImGui::End(); // end window

        window.clear(bgColor); // fill background with color
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}