#include "InputManager.h"

/*
thor::Action InputManager::a()
{
	//thor::Action a(sf::Keyboard::X, thor::Action::PressOnce);
}
*/
//InputManager::InputManager(sf::Event& event) : event_(event)
//{
//}


InputManager::InputManager()
{
}

void InputManager::CheckInput()
{

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

void InputManager::ProcessEventInput(const sf::Event& event) const
{
	switch (event.type)
	{
	case::sf::Event::KeyPressed:
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				if (p_game_manager->IsPaused())
				{
					p_game_manager->pPlayerGui->SetScreenActive(&PlayerGui::GamePlayScreen);
					p_game_manager->SetAllEntitiesActiveState(true);
				}
				else
				{
					p_game_manager->pPlayerGui->SetScreenActive(&PlayerGui::GamePausedScreen);
					p_game_manager->SetAllEntitiesActiveState(false);
				}

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
			//default:
			//	{
			//		break;
			//	}
		}
	}
}
