#include "GameManager.h"

GameManager::GameManager()
{
	EntityManager = std::make_unique<mat_m::EntityManager>();
}
