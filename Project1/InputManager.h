#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "PlayerCharacter.h"
#include "GameManager.h"

//using namespace sf;
class InputManager
{
public:
	typedef void (InputManager::* fptr_input)();
	fptr_input input_scheme_;
	std::shared_ptr<PlayerCharacter> p_player_;
	std::shared_ptr<GameManager> p_game_manager;
	sf::Event* event_ = nullptr;
	//int button = -1;
public:
	InputManager();

	void CheckInput();
	void ProcessEventInput(const sf::Event& event) const;
};

//if (event_->type == sf::Event::MouseButtonReleased && event_->mouseButton.button == sf::Mouse::Right)
//	{
//		std::cout << "button released";
//	}
//}
