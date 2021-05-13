#pragma once
#include "IManager.h"
#include <SFML/Graphics.hpp>
#include "PlayerCharacter.h"
#include <iostream>

class PlayerGui : public IManager
{
public:
	PlayerGui();
	const float BAR_MAX_SIZE = 93;
	
	sf::RectangleShape hp_back_;
	
	sf::Texture bar_texture_;
	sf::Sprite bar_sprite_;
	sf::RectangleShape stamina_back_;
	sf::Text score_;

	PlayerCharacter* p_player_;

	void ShowGameplayGui(sf::RenderWindow &window) const;
	void ChangeHpBar(int value);
	void ChangeStaminaBar(int value);
	void ReduceStaminaBar(int value);
	void Update() override;
private:
	
};

