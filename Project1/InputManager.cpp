#include "InputManager.h"
#include "PlayerCharacter.h"


InputManager::InputManager()
{
	input_scheme_ = &InputManager::GamePlayScheme;
}

void InputManager::CheckInput(const sf::Event& event)
{
	(this->*input_scheme_)(event);
}

void InputManager::ProcessEventInput(const sf::Event& event)
{

}

void InputManager::GamePlayScheme(const sf::Event& event)
{

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	p_player_->MoveUp();
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	p_player_->MoveDown();
	//}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	//{
	//	p_player_->ChargeAttack();
	//}

	switch (event.type)
	{
	case::sf::Event::KeyPressed:
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
				p_game_manager->pPlayerGui->SetScreenActive(&PlayerGui::GamePausedScreen);
				p_game_manager->SetAllEntitiesActiveState(false);
				input_scheme_ = &InputManager::PausedScheme;
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
		{
			p_player_->SetMovingUp(true);
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
		{
			p_player_->SetMovingDown(true);
		}
	}
	case sf::Event::KeyReleased:
	{
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
		{
			p_player_->SetMovingUp(false);
		}
		if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S)
		{
			p_player_->SetMovingDown(false);
		}
	}
	case sf::Event::MouseButtonPressed:
	{
		int button = event.mouseButton.button;
		if (event.type == sf::Event::MouseButtonPressed && button == 1)
		{
			p_player_->SetBlocking(true);
			break;
		}
		if (event.type == sf::Event::MouseButtonPressed && button == 0)
		{
			p_player_->SetShooting(true);
		}
	}

	//case sf::Event::MouseButtonPressed: {} // fall-through
	case sf::Event::MouseButtonReleased:
	{
		int button = event.mouseButton.button;
		if (event.type == sf::Event::MouseButtonReleased && button == 1)
		{
			p_player_->SetBlocking(false);
			break;
		}
		if (event.type == sf::Event::MouseButtonReleased && button == 0)
		{
			p_player_->SetShooting(false);
			break;
		}
	}
	}
}

void InputManager::PausedScheme(const sf::Event& event)
{
	switch (event.type)
	{
	case::sf::Event::KeyPressed:
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			p_game_manager->pPlayerGui->SetScreenActive(&PlayerGui::GamePlayScreen);
			p_game_manager->SetAllEntitiesActiveState(true);
			input_scheme_ = &InputManager::GamePlayScheme;
		}
	}
}
}

void InputManager::MainMenuScheme(const sf::Event& event)
{
}

void InputManager::GameOverScheme(const sf::Event& event)
{
	
}
