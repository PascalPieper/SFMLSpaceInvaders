#include "EntityManager.h"

EntityManager::EntityManager()
{
}

void EntityManager::CreateBackground(std::string EntityName, sf::Vector2f spawnPosition)
{
	std::shared_ptr<Entity> Background = std::make_shared<Entity>();
	//Background->setPosition(spawnPosition);
	_SharedBackgrounds.push_back(&Background);
}

void EntityManager::CreatePlayer()
{
	auto newPlayer = new PlayerCharacter();
	_Players.push_back(newPlayer);
}

void EntityManager::CreateCollider(std::string EntityName)
{
	sf::Vector2f test{ 1.f, 2.f };
	std::shared_ptr<Entity> Bullet = std::make_shared<Entity>();
	//auto Bullet = new Entity();

}

void EntityManager::DeleteBackgrounds()
{
	for (int i = 0; i < _Backgrounds.size(); i++)
	{
		delete(_Backgrounds[i]);
	}
	_Backgrounds.clear();
}

void EntityManager::DeleteAllEntities()
{
	DeleteBackgrounds();
}
