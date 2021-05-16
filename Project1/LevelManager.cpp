#include "LevelManager.h"
#include "Enemy.h"
#include "SnakeEnemy.h"
#include "BigFishEnemy.h"
#include "Random_Utility.h"

LevelManager::LevelManager()
{
	fp_screen_update_ = &LevelManager::IdleState;
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
	if (boss_count_ == 0)
	{
		GenerateRandomBoss();
		boss_count_++;
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
		for (unsigned int i = 0; i < MAX_BOSSES; ++i)
		{
			GenerateRandomBoss();
			boss_count_++;
		}
	}
}

void LevelManager::GenerateRandomBoss()
{
	auto new_rng = Random_Utility::RandomInt(0, 2);
	while (new_rng == rng_result)
	{
		new_rng = Random_Utility::RandomInt(0, 2);
	}
	rng_result = new_rng;
	//int rnd_result = 0;
	switch (rng_result)
	{
	case 0:
		{
		p_game_manager_->CreateEntity<Enemy>(sf::Vector2f{ 300, -100 });
		break;
		}
	case 1:
		{
		p_game_manager_->CreateEntity<SnakeEnemy>(sf::Vector2f{ 300, -125 });
		break;
		}
	case 2:
		{
		p_game_manager_->CreateEntity<BigFishEnemy>(sf::Vector2f{ 300, -150 });
		break;
		}
	}
}
