#pragma once
#include "IManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AssetManager.h"
#include <memory>

class PlayerGui : public IManager
{
public:
	PlayerGui();
	std::shared_ptr<AssetManager> p_asset_manager_;
	
	typedef void (PlayerGui::* playergui_fptr)(sf::RenderWindow& window);
	playergui_fptr fptr_acitve_screen_;

	
	//playergui_fptr test;
	
	const float BAR_MAX_SIZE = 93;
	
	sf::RectangleShape hp_back_;
	sf::Sprite bar_sprite_;
	sf::RectangleShape stamina_back_;
	sf::Text score_;
	sf::Text paused_;
	sf::Font font_;

	sf::RectangleShape game_over_screen_ {sf::Vector2f{360, 203}};
	sf::Texture GameOverTexture;
	
	void ShowGameOverScreen(int score);
	void EnableGameOverScreen();
	void SetScreenActive(void (PlayerGui::*function)(sf::RenderWindow &window));
	//int operation(int x, int y, int (*function)(int, int)) { return function(x, y); }
	void GamePlayScreen(sf::RenderWindow& window);
	void GameOverScreen(sf::RenderWindow& window);
	void GamePausedScreen(sf::RenderWindow& window);
	
	void ShowGui(sf::RenderWindow &window);
	
	void ChangeHpBar(int value);
	void ChangeStaminaBar(float value);
	void ReduceStaminaBar(int value);
	void Update() override;
private:
	
};

