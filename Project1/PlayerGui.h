#pragma once
#include "IManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AssetManager.h"
#include <memory>
#include "GameManager.h"

class GameManager;
class PlayerGui : public IManager
{
public:
	PlayerGui();
	std::shared_ptr<AssetManager> p_asset_manager_;
	std::shared_ptr<GameManager> p_game_manager_;
	typedef void (PlayerGui::* playergui_fptr)(sf::RenderWindow& window);
	playergui_fptr fptr_acitve_screen_;

	
	//playergui_fptr test;
	
	const float BAR_MAX_SIZE = 93;
	
	sf::RectangleShape hp_back_;
	sf::RectangleShape retry_button_{ sf::Vector2f{60, 20} };
	sf::Sprite bar_sprite_;
	sf::RectangleShape stamina_back_;
	sf::Text score_;
	sf::Text score_text_;
	sf::Text paused_text_;
	sf::Font font_;

	sf::RectangleShape game_over_screen_ {sf::Vector2f{360, 203}};
	sf::Texture game_over_texture_;
	sf::Texture retry_texture_;

	void Start();
	void CreateBackgrounds();
	void ShowGameOverScreen(int score);
	void EnableGameOverScreen();
	void SetScreenActive(void (PlayerGui::*function)(sf::RenderWindow &window));
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

