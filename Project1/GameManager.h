#pragma once
#include <map>
#include "Entity.h"
#include "SaveGameManager.h"
#include "AssetManager.h"
#include <memory>
#include <vector>
class Entity;
class GameManager
{
public:
	GameManager();

public:
	mat_m::SaveGameManager* pSaveGameManager;
	AssetManager* pAssetManager;
	

private:
	sf::Clock clock;
	float _deltaTime = 0;
	std::map<unsigned int, std::shared_ptr<Entity>> Entities;
	std::vector<unsigned int> DrawEnties;
	unsigned int count = 0;
public:
	float GetDeltaTime() { return _deltaTime; }
	void RefreshDeltatime();
	void SortByDrawIndex();


	std::shared_ptr<Entity> getEntity(unsigned int id);

	template<typename T>
	std::shared_ptr<T> CreateEntity(sf::Vector2f SpawnPosition);

	template<typename T>
	std::shared_ptr<T> CreateEntity(sf::Vector2f SpawnPosition, sf::Color color, float FadeDuration, sf::Vector2f size);
	//std::shared_ptr<Entity> CreateEntity(sf::Vector2f SpawnPosition);

	//std::shared_ptr<Entity> CreateBullet(sf::Vector2f SpawnPosition);
	void Update();
	void Draw(sf::RenderWindow &window);
};

template<typename T>
inline std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f SpawnPosition)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(SpawnPosition);
	NewEntity->pGameManager = this;
	NewEntity->GetEntitySprite().setTexture(pAssetManager->LoadTexture(NewEntity->getTextureName(), NewEntity->getTexturePath()));
	Entities.insert({ count, NewEntity });
	NewEntity->setPosition(SpawnPosition);
	count++;
	return NewEntity;
}

/*
template<typename T>
inline std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f SpawnPosition, sf::Color color, float FadeDuration, sf::Vector2f size)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(SpawnPosition, color, FadeDuration, size);
	NewEntity->pGameManager = this;
	NewEntity->EntitySprite.setTexture(pAssetManager->LoadTexture(NewEntity->TextureName, NewEntity->TEXTURE_PATH));
	Entities.insert({ count, NewEntity });
	NewEntity->EntitySprite.setPosition(SpawnPosition);
	count++;
	return NewEntity;
}
*/
