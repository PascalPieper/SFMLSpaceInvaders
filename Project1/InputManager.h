#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "PlayerCharacter.h"

//using namespace sf;
class InputManager
{
public:
	std::shared_ptr<PlayerCharacter> p_player_;

public:
	explicit InputManager();

	void CheckInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			p_player_->MoveUp();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			p_player_->MoveDown();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			p_player_->ChargeAttack();
		}
	}
};
