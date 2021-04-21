#include "GameManager.h"
class Entity;
GameManager::GameManager()
{
}

Entity* GameManager::getEntity(unsigned int id)
{
	return Entities.find(id)->second;
}

void GameManager::CreateEntity(sf::Vector2f SpawnPosition)
{
	Entity* NewEntity = new Entity(SpawnPosition);
	NewEntity->pGameManager = this;
	Entities.insert({ count, NewEntity });
	count++;
}

void GameManager::Update()
{
	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->Update();
	}
}
//NOT IMPLEMENTED
void GameManager::Draw() 
{
	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->_sprite;
	}
}
