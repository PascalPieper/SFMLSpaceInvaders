#include "GameManager.h"

GameManager::GameManager()
{
	EntityManager = new mat_m::EntityManager();
	EntityManager->pgm = this;
}
