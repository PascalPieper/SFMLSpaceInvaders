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
#include "PlayerGui.h"
#include "IPlayerCharacter.h"
#include "LevelManager.h"

class Entity;
class LevelManager;
class PlayerGui;
class GameManager
{
public:
	GameManager();

	const int screen_width_ = 360;
	const int screen_height_ = 203;

	unsigned int current_player_id_;
	unsigned int current_boss_id_;
	bool paused_;


	std::shared_ptr<mat_m::SaveGameManager> pSaveGameManager;
	std::shared_ptr<AssetManager> pAssetManager;
	std::shared_ptr<AudioManager> pAudioManager;
	std::shared_ptr<PlayerGui> pPlayerGui;
	std::shared_ptr<LevelManager> pLevelManager;
	//std::shared_ptr<PlayerGui> pPlayerGui;
	std::shared_ptr<IPlayerCharacter> current_player_character_;
	unsigned int CurrentPlayerCharacterID;

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
	std::array<std::map<unsigned int, std::shared_ptr<Entity>>, 8> CollisionListings;

	//std::vector <Entity*> CollisionListings[8];

	void RegisterToIndex(unsigned int index, unsigned int id, std::shared_ptr<Entity> entity);
	void UnRegisterFromIndex(unsigned int index, unsigned int id);
	//void RegisterToCollision(std::vector<unsigned int> index);
	//virtual std::vector<unsigned int>& RegisterEntiyCollisionTargets();
	//template<typename T>
	//std::shared_ptr<T> RequestPollEntity(std::string UniquePollName, sf::Vector2f position);

	void RemoveEntity(unsigned int ID);
	std::shared_ptr<Entity> getEntity(unsigned int id);

	template <typename T>
	std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position);

	template <typename T>
	void ProcessEntity(std::shared_ptr<T> NewEntity, sf::Vector2f spawn_position);
	//template<typename T>
	//std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, std::string texture_path, std::string texture_name);
	template <typename T, typename A>
	std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, A param_a);

	template <typename T, typename A, typename B>
	std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b);

	template <typename T, typename A, typename B, typename C>
	std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b, C param_c);

	template <typename T, typename A, typename B, typename C, typename D>
	std::shared_ptr<T> CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b, C param_c, D param_d);

	//template<typename T>
	//std::shared_ptr<T> CreateScreenEffect(sf::Vector2f SpawnPosition);
	template <typename T>
	std::shared_ptr<T> GetEntityByType(unsigned int id);

	void Update();
	void Draw(sf::RenderWindow& window);

	void SetAllEntitiesActiveState(bool active);

public:

	bool IsPaused() const
	{
		return paused_;
	}

	void SetPaused(bool paused)
	{
		paused_ = paused;
	}
};


template <typename T>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position);
	ProcessEntity(NewEntity, spawn_position);
	return NewEntity;
}

template <typename T>
void GameManager::ProcessEntity(std::shared_ptr<T> NewEntity, sf::Vector2f spawn_position)
{
	NewEntity->pGameManager = this;
	NewEntity->GetEntitySprite().setTexture(
		pAssetManager->LoadTexture(NewEntity->getTextureName(), NewEntity->getTexturePath()));
	if (NewEntity->IsAnimated())
	{
		NewEntity->GetEntitySprite().setTextureRect(NewEntity->texture_animation_offset);
	}

	NewEntity->SetID(count);
	Entities.insert({count, NewEntity});
	NewEntity->RegisterEntity();
	count++;
	NewEntity->Start();
	NewEntity->SetPosition(spawn_position);
}

template <typename T, typename A>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position, A param_a)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position, param_a);
	ProcessEntity(NewEntity, spawn_position);
	return NewEntity;
}

template <typename T, typename A, typename B>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position, param_a, param_b);
	ProcessEntity(NewEntity, spawn_position);
	return NewEntity;
}

template <typename T, typename A, typename B, typename C>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b, C param_c)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position, param_a, param_b, param_c);
	ProcessEntity(NewEntity, spawn_position);
	return NewEntity;
}

template <typename T, typename A, typename B, typename C, typename D>
std::shared_ptr<T> GameManager::CreateEntity(sf::Vector2f spawn_position, A param_a, B param_b, C param_c, D param_d)
{
	std::shared_ptr<T> NewEntity = std::make_shared<T>(spawn_position, param_a, param_b, param_c, param_d);
	ProcessEntity(NewEntity, spawn_position);
	return NewEntity;
}

template <typename T>
std::shared_ptr<T> GameManager::GetEntityByType(unsigned id)
{
	auto result = Entities.find(id)->second;
	return std::dynamic_pointer_cast<T>(result);
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
		result->SetActiveAndDrawn(true);
		//result->reset();
		return result;
	}
	else
	{
		return CreateEntity<T>(position);
	}
}
*/
