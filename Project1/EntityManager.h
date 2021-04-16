#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <map>
#include <vector>
#include "Entity.h"
#include "IManager.h"
#include "PlayerCharacter.h"
using namespace PP;
class EntityManager
{
public:
	EntityManager();
public:
	//std::map<std::unique_ptr<Entity>, std::string> m_Entities;

	std::vector<std::shared_ptr<Entity>*> _SharedBackgrounds;

	std::vector<Entity*> _Backgrounds;
	std::vector<Entity*> _Colliders;
	std::vector<Entity*> _Actors;
	std::vector<IPlayerCharacter*> _Players;
public:
	void CreateBackground(std::string EntityName, sf::Vector2f spawnPosition);
	void CreatePlayer();
	void CreateCollider(std::string EntityName);
	void DeleteBackgrounds();
	void DeleteAllEntities();

private:
};