#pragma once
#include "GameManager.h"
#include <memory>
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
};