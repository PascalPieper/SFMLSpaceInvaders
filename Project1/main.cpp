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
    window.setFramerateLimit(90);
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
}
*/

#include "imgui.h"
#include "imgui-SFML.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include "CompHeader.h"
#include "ScreenFade.h"
#include "Enemy.h"
#include "BouncyBullet.h"
#include "InputManager.h"
#include "PlayerCharacter.h"
#include "AudioManager.h"
#include "InputManager.h"

int main()
{
#pragma region GameManagerSetup
	auto gm = std::make_shared<GameManager>();
    auto save_game_manager = std::make_shared<mat_m::SaveGameManager>("Morus Kara");
    auto asset_manager = std::make_shared<AssetManager>();
    auto audio_manager = std::make_shared<AudioManager>();
    auto input_manager = std::make_shared<InputManager>();
	
    gm->pSaveGameManager = save_game_manager;
    gm->pAssetManager = asset_manager;
    gm->pAudioManager = audio_manager;

    sf::RenderWindow window(sf::VideoMode(360, 203), "Morus Kara");
    window.setFramerateLimit(165);
    window.setVerticalSyncEnabled(true);
    window.setKeyRepeatEnabled(false);

    window.setSize(sf::Vector2u{ 1920, 1080 });
#pragma endregion GameManagerSetup

#pragma region backgroundInit
    ImGui::SFML::Init(window);
    auto Background01 = 
        gm->CreateEntity<ScrollingBackground>(sf::Vector2f{ 0,0 }, "Assets/Background/1_BG_Sky_duplicated.png", "Background01", 0);
    auto Background02 =
        gm->CreateEntity<ScrollingBackground>(sf::Vector2f{ 0,0 }, "Assets/Background/2_Clouds_duplicated.png", "Background02", 12.f);
    auto Background03 =
        gm->CreateEntity<ScrollingBackground>(sf::Vector2f{ 0,0 }, "Assets/Background/3_Mountain_duplicated.png", "Background03", 25.f);
    auto Background04 =
        gm->CreateEntity<ScrollingBackground>(sf::Vector2f{ 0,0 }, "Assets/Background/4_Dune_1_duplicated.png", "Background04", 55.f);
    auto Background05 =
        gm->CreateEntity<ScrollingBackground>(sf::Vector2f{ 0,0 }, "Assets/Background/5_Dune_2_duplicated.png", "Background05", 110.f);
    auto Background06 =
        gm->CreateEntity<ScrollingBackground>(sf::Vector2f{ 0,0 }, "Assets/Background/6_Dune_3_duplicated.png", "Background06", 200.f);
	
    gm->pAudioManager->PlayMusic("AnikInvaders.wav");
    auto Player = gm->CreateEntity<PlayerCharacter>(sf::Vector2f{ 20,0 });
    input_manager->p_player_ = Player;
#pragma endregion backgroundInit

    //window.resetGLStates();
	
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
#pragma region ImGuiDebugging
        ImGui::Begin("Sample window"); // begin window
        if (ImGui::Button("Spawn Enemy")) 
        {
            gm->CreateEntity<Enemy>(sf::Vector2f{ 300, 5 });
        }
        float bgspeed01;
        if (ImGui::SliderFloat("Background01", &bgspeed01, 0, 1000.f))
        {
            Background01->SetMovementspeed(bgspeed01);
        }
        float bgspeed02;
        if (ImGui::SliderFloat("Background02", &bgspeed02, 0, 1000.f))
        {
            Background02->SetMovementspeed(bgspeed02);
        }
        float bgspeed03;
        if (ImGui::SliderFloat("Background03", &bgspeed03, 0, 1000.f))
        {
            Background03->SetMovementspeed(bgspeed03);
        }
        float bgspeed04;
        if (ImGui::SliderFloat("Background04", &bgspeed04, 0, 1000.f))
        {
            Background04->SetMovementspeed(bgspeed04);
        }
        float bgspeed05;
        if (ImGui::SliderFloat("Background05", &bgspeed05, 0, 1000.f))
        {
            Background05->SetMovementspeed(bgspeed05);
        }
        float bgspeed06;
        if (ImGui::SliderFloat("Background06", &bgspeed06, 0, 1000.f))
        {
            Background06->SetMovementspeed(bgspeed06);
        }
        if (ImGui::Button("Spawn Bullet"))
        {
            std::cout << window.getDefaultView().getSize().x;
            auto bullet = gm->CreateEntity<AcceleratedBullet>(sf::Vector2f{ 360, 100});
        }
        if (ImGui::Button("Spawn BouncyBullet"))
        {
            std::cout << window.getDefaultView().getSize().x;
            gm->CreateEntity<BouncyBullet>(sf::Vector2f{ 360, 100 });
        }
#pragma endregion ImGuiDebugging
        input_manager->CheckInput();

        ImGui::End();
        gm->Update();
        window.clear();
        gm->Draw(window);

        ImGui::SFML::Render(window);
        window.display();
        gm->RefreshDeltatime();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
