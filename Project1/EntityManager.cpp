#include "EntityManager.h"

mat_m::EntityManager::EntityManager()
{
}


void mat_m::EntityManager::SendInput()
{
}

void mat_m::EntityManager::CreateBackground(std::string EntityName, sf::Vector2f spawnPosition)
{
	std::shared_ptr<mat::Entity> Background = std::make_shared<mat::Entity>();
	//Background->setPosition(spawnPosition);
	_SharedBackgrounds.push_back(&Background);
}

void mat_m::EntityManager::CreatePlayer()
{
	auto newPlayer = new PlayerCharacter();
	_Players.push_back(newPlayer);
}

void mat_m::EntityManager::CreateCollider(std::string EntityName)
{
	sf::Vector2f test{ 1.f, 2.f };
	std::shared_ptr<mat::Entity> Bullet = std::make_shared<mat::Entity>();
	//auto Bullet = new Entity();

}

void mat_m::EntityManager::DeleteBackgrounds()
{
	for (int i = 0; i < _Backgrounds.size(); i++)
	{
		delete(_Backgrounds[i]);
	}
	_Backgrounds.clear();
}

void mat_m::EntityManager::DeleteAllEntities()
{
	DeleteBackgrounds();
}
