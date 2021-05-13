#pragma once
#include <map>
#include "Entity.h"
#include "SaveGameManager.h"
#include "AssetManager.h"
#include <memory>
#include <vector>
#include <array>
#include "AudioManager.h"
#include <algorithm>
#include "imgui.h"
#include "imgui-SFML.h"
class Entity;
//class CollisionEntity;
class GameManager
{
public:
	GameManager();

	const int screen_width_ = 360;
	const int screen_height_ = 203;
public:
	std::shared_ptr<mat_m::SaveGameManager> pSaveGameManager;
	std::shared_ptr<AssetManager> pAssetManager;
	std::shared_ptr<AudioManager> pAudioManager;
	bool ShowCollisionBoxes = false;
private:
	sf::Clock clock;
	float _deltaTime = 0;
	//std::map<unsigned int, std::shared_ptr<Entity>> Entities;

	std::map<unsigned int, std::shared_ptr<Entity>> Entities;
	
	std::vector<unsigned int> DrawEnties;
	unsigned int count = 0;
public:
	float GetDeltaTime() { return _deltaTime; }
	void RefreshDeltatime();
	void SortByDrawIndex();

	std::map<std::string, std::shared_ptr<Entity>> InactivePollings;

	//Vectors for Collision detection
	std::array <std::map <unsigned int, std::shared_ptr<Entity>>, 8> CollisionListings;

	//std::vector <Entity*> CollisionListings[8];

	void RegisterToIndex(unsigned int index, unsigned int id, std::shared_ptr<Entity> entity);
	void UnRegisterFromIndex(unsigned int index, unsigned int id);
	//void RegisterToCollision(std::vector<unsigned int> index);
	//virtual std::vector<unsigned int>& RegisterEntiyCollisionTargets();
	//template<typename T>
	//std::shared_ptr<T> RequestPollEntity(std::string UniquePollName, sf::Vector2f position);

	void RemoveEntity(unsigned int ID);
	std::shared_ptr<Entity> getEntity(unsigned int id);

	template<typename T>
	std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position);

	//template<typename T>
	//std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, std::string texture_path, std::string texture_name);
	template<typename T, typename  A>
	inline std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, A param_a);
	
	template<typename T, typename  A, typename B>
	inline std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b);

	template<typename T, typename  A, typename B, typename C>
	inline std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b, C param_c);
	
	template<typename T, typename  A, typename B, typename C, typename D>
	inline std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b, C param_c, D param_d);
	
	//template<typename T>
	//std::shared_ptr<T> CreateScreenEffect(sf::Vector2f SpawnPosition);

	void Update();
	void Draw(sf::RenderWindow &window);
};



template<typename T>
inline std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position);
	NewEntity->pGameManager = this;
	NewEntity->GetEntitySprite().setTexture(pAssetManager->LoadTexture(NewEntity->getTextureName(), NewEntity->getTexturePath()));
	NewEntity->GetEntitySprite().setTextureRect(NewEntity->texture_animation_offset);
	NewEntity->SetID(count);
	Entities.insert({ count, NewEntity });
	NewEntity->RegisterEntity();
	count++;
	NewEntity->SetPosition(spawn_position);
	return NewEntity;
}

template <typename T, typename A>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position, A param_a)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position, param_a);
	NewEntity->pGameManager = this;
	NewEntity->GetEntitySprite().setTexture(pAssetManager->LoadTexture(NewEntity->getTextureName(), NewEntity->getTexturePath()));
	NewEntity->SetID(count);
	Entities.insert({ count, NewEntity });
	NewEntity->RegisterEntity();
	count++;
	NewEntity->SetPosition(spawn_position);
	return NewEntity;
}

template<typename T, typename  A, typename B>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position, param_a, param_b);
	NewEntity->pGameManager = this;
	NewEntity->GetEntitySprite().setTexture(pAssetManager->LoadTexture(NewEntity->getTextureName(), NewEntity->getTexturePath()));
	NewEntity->SetID(count);
	Entities.insert({ count, NewEntity });
	NewEntity->RegisterEntity();
	count++;
	NewEntity->SetPosition(spawn_position);
	return NewEntity;
}

template <typename T, typename A, typename B, typename C>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b, C param_c)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position, param_a, param_b, param_c);
	NewEntity->pGameManager = this;
	NewEntity->GetEntitySprite().setTexture(pAssetManager->LoadTexture(NewEntity->getTextureName(), NewEntity->getTexturePath()));
	NewEntity->SetID(count);
	Entities.insert({ count, NewEntity });
	NewEntity->RegisterEntity();
	count++;
	NewEntity->SetPosition(spawn_position);
	return NewEntity;
}

template <typename T, typename A, typename B, typename C, typename D>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b, C param_c, D param_d)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position, param_a, param_b, param_c, param_d);
	NewEntity->pGameManager = this;
	NewEntity->GetEntitySprite().setTexture(pAssetManager->LoadTexture(NewEntity->getTextureName(), NewEntity->getTexturePath()));
	NewEntity->SetID(count);
	Entities.insert({ count, NewEntity });
	NewEntity->RegisterEntity();
	count++;
	NewEntity->SetPosition(spawn_position);
	return NewEntity;
}

/*
template<typename T>
inline std::shared_ptr<T> GameManager::RequestPollEntity(std::string UniquePollName, sf::Vector2f position)
{
	auto KeyValuePair = InactivePollings.find(UniquePollName);
	if (KeyValuePair != InactivePollings.end())
	{
		auto& result = KeyValuePair->second;
		result->SetPosition(position);
		result->SetActiveAndRendered(true);
		//result->reset();
		return result;
	}
	else
	{
		return CreateEntity<T>(position);
	}
}
*/
