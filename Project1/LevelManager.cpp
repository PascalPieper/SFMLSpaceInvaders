#include "LevelManager.h"
#include "Enemy.h"

LevelManager::LevelManager()
{
	//fp_screen_update_ = &LevelManager::IdleState;
	fp_screen_update_ = &LevelManager::EarlyGameState;
}

void LevelManager::UpdateState()
{
	(this->*fp_screen_update_)();
}

void LevelManager::IdleState()
{
	state_clock_.restart();
}

void LevelManager::EarlyGameState()
{
	if (boss_count_ < 1)
	{
		GenerateRandomBoss();
	}
	if (state_clock_.getElapsedTime().asSeconds() > DIFFICULTY_DELAY)
	{
		fp_screen_update_ = &LevelManager::EndGameState;
	}
}

void LevelManager::EndGameState()
{
	if (boss_count_ == 0)
	{
		for (int i = 0; i < MAX_BOSSES; ++i)
		{
			GenerateRandomBoss();
		}
	}
}

void LevelManager::GenerateRandomBoss()
{
	//auto rnd_result = Random_Utility::RandomInt(0, 2);
	int rnd_result = 0;
	switch (rnd_result)
	{
	case 0:
		{
		p_game_manager_->CreateEntity<Enemy>(sf::Vector2f{ 300, -100 });
		}
	case 1:
		{

		}
	default:
		{
			
		}
	}
}
