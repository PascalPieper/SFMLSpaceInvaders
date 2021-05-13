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

	bar_texture_.loadFromFile("assets/gui/HP_Bar.png");
	bar_sprite_.setTexture(bar_texture_);
	bar_sprite_.setPosition(5, 8);
	
}

void PlayerGui::ShowGameplayGui(sf::RenderWindow &window) const
{
	std::cout << hp_back_.getSize().y;
	window.draw(hp_back_);
	window.draw(stamina_back_);
	window.draw(score_);
	window.draw(bar_sprite_);
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

void PlayerGui::ChangeStaminaBar(int value)
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
