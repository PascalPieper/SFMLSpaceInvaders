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
#include "PlayerGui.h"
#include "PlayerManager.h"
#include "SnakeEnemy.h"
#include "BigFishEnemy.h"
#include "BarrageBullet.h"

int main()
{
#pragma region GameManagerSetup
	auto gm = std::make_shared<GameManager>();
    auto save_game_manager = std::make_shared<mat_m::SaveGameManager>("Morus Kara");
    auto asset_manager = std::make_shared<AssetManager>();
    auto audio_manager = std::make_shared<AudioManager>();
    auto input_manager = std::make_shared<InputManager>();
    auto level_manager = std::make_shared<LevelManager>();
    auto Playergui = std::make_shared<PlayerGui>();
    
    gm->pSaveGameManager = save_game_manager;
    gm->pAssetManager = asset_manager;
    gm->pAudioManager = audio_manager;
    gm->pPlayerGui = Playergui;
    gm->pLevelManager = level_manager;
    gm->pInputManager = input_manager;
	
    input_manager->p_game_manager = gm;
    level_manager->p_game_manager_ = gm;
    Playergui->p_game_manager_ = gm;

    Playergui->p_asset_manager_ = asset_manager;
    //gm->CurrentPlayerCharacterID = Player->GetID();
#pragma endregion GameManagerSetup
	
    sf::RenderWindow window(sf::VideoMode(360, 203), "Morus Kara", sf::Style::Default);
    sf::View view1(sf::FloatRect(0.f, 0.f, 360.f, 203.f));
    window.setView(view1);
    window.setFramerateLimit(144);
    window.setVerticalSyncEnabled(false);
    window.setKeyRepeatEnabled(false);
	
    ImGui::SFML::Init(window);

    gm->pAudioManager->PlayMusic("Assets/Music/AnikInvaders.wav"); //FIX ME: Transfer to audio manager later

    Playergui->Start();
    //window.resetGLStates();
    auto Player = gm->CreateEntity<PlayerCharacter>(sf::Vector2f{ 20,0 });
    gm->current_player_id_ = Player->GetID();
    auto Playermanager = std::make_shared<PlayerManager>(Player);
    //gm->current_player_character_ = Player;
    input_manager->p_player_ = gm->GetEntityByType<PlayerCharacter>(gm->current_player_id_);
    sf::Clock deltaClock;

    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);
            input_manager->CheckInput(event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        ImGui::SFML::Update(window, deltaClock.restart());
#pragma region ImGuiDebugging
    	
        ImGui::Begin("Debugging");
        if (ImGui::Button("Spawn Enemy"))
        {
            gm->CreateEntity<Enemy>(sf::Vector2f{ 300, -100 });
        }
        if (ImGui::Button("Spawn Snake Enemy"))
        {
            gm->CreateEntity<SnakeEnemy>(sf::Vector2f{ 300, -100 });
        }

        if (ImGui::Button("Spawn Big Fish Enemy"))
        {
            gm->CreateEntity<BigFishEnemy>(sf::Vector2f{ 300, -150 });
        }
        if (ImGui::Button("Toggle Hitboxes"))
        {
            gm->ShowCollisionBoxes = !gm->ShowCollisionBoxes;
        }
#pragma endregion ImGuiDebugging

    	
        //input_manager->CheckInput();
        ImGui::End();
        gm->Update();
        level_manager->UpdateState();
        window.clear();
        gm->Draw(window);
        Playergui->ShowGui(window);
        ImGui::SFML::Render(window);
        window.display();
        gm->RefreshDeltatime();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
