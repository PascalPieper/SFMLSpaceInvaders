#include "PlayerGui.h"


PlayerGui::PlayerGui()
{
	stamina_back_.setSize(sf::Vector2f{ 11, 93 });
	stamina_back_.setPosition(5, 101);
	stamina_back_.setFillColor(sf::Color{ 10, 142, 85 });
	hp_back_.setSize(sf::Vector2f{ 11, 93 });
	hp_back_.setPosition(16, 101);
	hp_back_.setFillColor(sf::Color{ 168, 28, 27 });
	hp_back_.setRotation(180);

	//bar_texture_.loadFromFile("assets/gui/HP_Bar.png");
	std::string test = "hp_bar";
	
	bar_sprite_.setPosition(5, 8);

	GameOverTexture.loadFromFile("Assets/gui/GAME_OVER.png");
	game_over_screen_.setTexture(&GameOverTexture);
	SetScreenActive(&PlayerGui::GamePlayScreen);
}

void PlayerGui::ShowGameOverScreen(int score)
{
	
}

void PlayerGui::EnableGameOverScreen()
{
	
}

void PlayerGui::SetScreenActive(void(PlayerGui::* function)(sf::RenderWindow &window))
{
	fptr_acitve_screen_ = function;
}

void PlayerGui::GamePlayScreen(sf::RenderWindow& window)
{
	window.draw(hp_back_);
	window.draw(stamina_back_);
	window.draw(score_);
	window.draw(bar_sprite_);
}

void PlayerGui::GameOverScreen(sf::RenderWindow& window)
{
	window.draw(game_over_screen_);
}

void PlayerGui::GamePausedScreen(sf::RenderWindow& window)
{
	window.draw(paused_);
}

void PlayerGui::ShowGui(sf::RenderWindow &window)
{
	(this->*fptr_acitve_screen_)(window);
	
	bar_sprite_.setTexture(p_asset_manager_->LoadTexture("hp_bar", "assets/Gui/HP_Bar.png"));

	//window.draw(game_over_screen_);
}

void PlayerGui::ChangeHpBar(int value)
{
	auto result = hp_back_.getSize();
	if (value + result.y >= BAR_MAX_SIZE)
	{
		hp_back_.setSize(sf::Vector2f{ result.x, BAR_MAX_SIZE });
	}
	else
	{
		hp_back_.setSize(sf::Vector2f{ result.x, result.y += value });
	}
	
}

void PlayerGui::ChangeStaminaBar(float value)
{
	auto result = stamina_back_.getSize();
	if (value + result.y >= BAR_MAX_SIZE)
	{
		stamina_back_.setSize(sf::Vector2f{ result.x, BAR_MAX_SIZE });
	}
	else if (value + result.y <= 0)
	{
		stamina_back_.setSize(sf::Vector2f{ result.x, 0});
	}
	else
	{
		stamina_back_.setSize(sf::Vector2f{ result.x, result.y += value });
	}
}

void PlayerGui::Update()
{
}
