#include "LevelManager.h"

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
	
}
