#pragma once
#include "GameManager.h"
#include <memory>
//class Entity;
class GameManager;
class LevelManager
{
public:
	LevelManager();
	std::shared_ptr<GameManager> p_game_manager_;
	typedef void (LevelManager::* fptr_update)();
	fptr_update fp_screen_update_;

	void UpdateState();
	void IdleState();
	void EarlyGameState();
	void EndGameState();

	void GenerateRandomBoss();

protected:
	int rng_result = 1;
	unsigned int boss_count_ = 0;
	unsigned int mob_count_ = 0;
	unsigned int score_ = 0;
	sf::Clock state_clock_;

	const unsigned int MAX_BOSSES = 2;
	const float DIFFICULTY_DELAY = 50.f;
public:
	unsigned GetBossCount() const
	{
		return boss_count_;
	}

	void ChangeBossCount(unsigned boss_count)
	{
		boss_count_ += boss_count;
	}

	unsigned GetMobCount() const
	{
		return mob_count_;
	}

	void SetMobCount(unsigned mob_count)
	{
		mob_count_ = mob_count;
	}

	unsigned GetScore() const
	{
		return score_;
	}

	void SetScore(unsigned score)
	{
		score_ = score;
	}
};
