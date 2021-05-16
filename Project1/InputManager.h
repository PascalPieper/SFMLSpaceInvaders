#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "GameManager.h"

class GameManager;
class PlayerCharacter;
//using namespace sf;
class InputManager
{
public:
	typedef void(InputManager::* InputScheme)(const sf::Event& event);
	InputScheme input_scheme_;
	std::shared_ptr<GameManager> p_game_manager;
	std::shared_ptr<PlayerCharacter> p_player_;
	sf::Event* event_ = nullptr;
	//int button = -1;
public:
	InputManager();

	void CheckInput(const sf::Event& event);
	void ProcessEventInput(const sf::Event& event);
	void GamePlayScheme(const sf::Event& event);
	void PausedScheme(const sf::Event& event);
	void MainMenuScheme(const sf::Event& event);
	void GameOverScheme(const sf::Event& event);
};

//if (event_->type == sf::Event::MouseButtonReleased && event_->mouseButton.button == sf::Mouse::Right)
//	{
//		std::cout << "button released";
//	}
//}
