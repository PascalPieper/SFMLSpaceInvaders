#include "GameManager.h"
class Entity;
GameManager::GameManager()
{
}

Entity* GameManager::getEntity(unsigned int id)
{
	return Entities.find(id)->second;
}

void GameManager::CreateEntity(std::string Path, unsigned int Layer, unsigned int CollisionIndex, sf::Vector2f SpawnPosition)
{
	Entity* NewEntity = new Entity(Path, Layer, CollisionIndex, SpawnPosition);
	NewEntity->pGameManager = this;
	Entities.insert({ count, NewEntity });
	count++;
}